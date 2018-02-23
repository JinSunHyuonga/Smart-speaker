#ifndef XML_PARSER_HPP
#define XML_PARSER_HPP
/**
 *  @file
 *  Class "GetConfig" provides the functions to read the XML data.
 *  @version 1.0
 */
#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMDocumentType.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/dom/DOMNodeIterator.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMText.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/XMLUni.hpp>
 
#include <string>
#include <stdexcept>
 
// Error codes
 
enum {
   ERROR_ARGS = 1,
   ERROR_XERCES_INIT,
   ERROR_PARSE,
   ERROR_EMPTY_DOCUMENT
};
 
class GetConfig
{
public:
   GetConfig();
  ~GetConfig();
   void readConfigFile(std::string&) throw(std::runtime_error);
  
   char *getWeatherSpeech() { return m_WeatherSpeech; };
 
private:
   xercesc::XercesDOMParser *m_ConfigFileParser;
   char* m_WeatherSpeech;
 
   // Internal class use only. Hold Xerces data in UTF-16 SMLCh type.
 
   XMLCh* TAG_Value1; 
   XMLCh* TAG_Value2;
   XMLCh* TAG_Value3;
   XMLCh* TAG_Value4;
   XMLCh* TAG_Value5;
   XMLCh* TAG_Value6;
   XMLCh* ATTR_WeatherSpeech;
};
#endif


