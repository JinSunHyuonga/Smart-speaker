#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <list>
 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "weatherparser.hpp"
#include <fstream>

using namespace xercesc;
using namespace std;

/**
 *  Constructor initializes xerces-C libraries.
 *  The XML tags and attributes which we seek are defined.
 *  The xerces-C DOM parser infrastructure is initialized.
 */
 
GetConfig::GetConfig()
{
   try
   {
      XMLPlatformUtils::Initialize();  // Initialize Xerces infrastructure
   }
   catch( XMLException& e )
   {
      char* message = XMLString::transcode( e.getMessage() );
      cerr << "XML toolkit initialization error: " << message << endl;
      XMLString::release( &message );
      // throw exception here to return ERROR_XERCES_INIT
   }
 
   // Tags and attributes used in XML file.
   // Can't call transcode till after Xerces Initialize()
   TAG_Value1 = XMLString::transcode("rss");
   TAG_Value2 = XMLString::transcode("channel");
   TAG_Value3 = XMLString::transcode("item");
   TAG_Value4 = XMLString::transcode("description");
   TAG_Value5 = XMLString::transcode("header");
   TAG_Value6 = XMLString::transcode("wf");
   ATTR_WeatherSpeech = XMLString::transcode("title");
 
   m_ConfigFileParser = new XercesDOMParser;
}
 
/**
 *  Class destructor frees memory used to hold the XML tag and
 *  attribute definitions. It als terminates use of the xerces-C
 *  framework.
 */
 
GetConfig::~GetConfig()
{
   // Free memory
 
   delete m_ConfigFileParser;
   if(m_WeatherSpeech)   XMLString::release( &m_WeatherSpeech );
 
   try
   {
      XMLString::release( &TAG_Value1 );
      XMLString::release( &TAG_Value2 );
      XMLString::release( &TAG_Value3 );
      XMLString::release( &TAG_Value4 );
      XMLString::release( &TAG_Value5 );
      XMLString::release( &TAG_Value6 );
      XMLString::release( &ATTR_WeatherSpeech );
   }
   catch( ... )
   {
      cerr << "Unknown exception encountered in TagNamesdtor" << endl;
   }
 
   // Terminate Xerces
 
   try
   {
      XMLPlatformUtils::Terminate();  // Terminate after release of memory
   }
   catch( xercesc::XMLException& e )
   {
      char* message = xercesc::XMLString::transcode( e.getMessage() );
 
      cerr << "XML ttolkit teardown error: " << message << endl;
      XMLString::release( &message );
   }
}
 
/**
 *  This function:
 *  - Tests the access and availability of the XML configuration file.
 *  - Configures the xerces-c DOM parser.
 *  - Reads and extracts the pertinent information from the XML config file.
 *
 *  @param in configFile The text string name of the HLA configuration file.
 */
 
void GetConfig::readConfigFile(string& configFile)
        throw( std::runtime_error )
{
   // Test to see if the file is ok.
 
   struct stat fileStatus;
 
   errno = 0;
   if(stat(configFile.c_str(), &fileStatus) == -1) // ==0 ok; ==-1 error
   {
       if( errno == ENOENT )      // errno declared by include file errno.h
          throw ( std::runtime_error("Path file_name does not exist, or path is an empty string.") );
       else if( errno == ENOTDIR )
          throw ( std::runtime_error("A component of the path is not a directory."));
       else if( errno == ELOOP )
          throw ( std::runtime_error("Too many symbolic links encountered while traversing the path."));
       else if( errno == EACCES )
          throw ( std::runtime_error("Permission denied."));
       else if( errno == ENAMETOOLONG )
          throw ( std::runtime_error("File can not be read\n"));
   }
 
   // Configure DOM parser.
 
   m_ConfigFileParser->setValidationScheme( XercesDOMParser::Val_Never );
   m_ConfigFileParser->setDoNamespaces( false );
   m_ConfigFileParser->setDoSchema( false );
   m_ConfigFileParser->setLoadExternalDTD( false );
 
   try
   {
      m_ConfigFileParser->parse( configFile.c_str() );
 
      // no need to free this pointer - owned by the parent parser object
      DOMDocument* xmlDoc = m_ConfigFileParser->getDocument();
 
      // Get the top-level element: NAme is "root". No attributes for "root"
       
      DOMElement* elementRoot = xmlDoc->getDocumentElement();
      if( !elementRoot ) throw(std::runtime_error( "empty XML document" ));
 
	DOMNodeList* WeatherChildren = elementRoot->getChildNodes(); 
//	const  XMLSize_t nodeCount = WeatherChildren->getLength();

	DOMNode* channel = WeatherChildren->item(1);
	DOMNodeList* channelChildren = channel->getChildNodes();

	DOMNode* item = channelChildren->item(13);
    DOMNodeList* itemChildren = item->getChildNodes();

	DOMNode* description = itemChildren->item(10);
    DOMNodeList* descriptionChildren = description->getChildNodes();

	DOMNode* body = descriptionChildren->item(3);
    DOMNodeList* bodyChildren = body->getChildNodes();

	DOMNode* data = bodyChildren->item(1);
    DOMNodeList* dataChildren = data->getChildNodes();

	DOMNode* currentNode = dataChildren->item(5) ;
	char* NodeValue ;
	NodeValue = XMLString::transcode(currentNode->getTextContent());
	cout << "temp = " << NodeValue << endl;

	currentNode = dataChildren->item(15) ;
	NodeValue = XMLString::transcode (currentNode->getTextContent());
	cout << "wfKor = " << NodeValue << endl;

   }
   catch( xercesc::XMLException& e )
   {
      char* message = xercesc::XMLString::transcode( e.getMessage() );
      ostringstream errBuf;
      errBuf << "Error parsing file: " << message << flush;
      XMLString::release( &message );
   }
}
 
int main()
{
//   system("DOMPrint \"http://www.weather.go.kr/wid/queryDFSRSS.jsp?zone=1168066000\" > test_data.xml");// stat file. Get ambigious segfault otherwise.

   string configFile = "test_data.xml";

   GetConfig appConfig;
   appConfig.readConfigFile(configFile);
	cout << "end" << endl; 
   return 0;
}
