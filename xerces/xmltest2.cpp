#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <iostream>

using namespace std;
using namespace xercesc;

int main(void)
{
	try{
		XMLPlatformUtils::Initialize();
	}
	catch(const XMLException &toCatch){
		char *message= XMLString::transcode(toCatch.getMessage());
		cout<<"Error during initialization!:\n"<<message<<"\n";
		XMLString::release(&message);
		return 1;
	}

	char *xmlFile= "test_data.xml";
	XercesDOMParser *parser= new XercesDOMParser();

	parser->setValidationScheme(XercesDOMParser::Val_Always);
	parser->setDoNamespaces(true);

	ErrorHandler *errHandler=(ErrorHandler*)new HandlerBase();
	parser->setErrorHandler(errHandler);

	try{
		parser->parse(xmlFile);
	}
	catch(const XMLException &toCatch){
		char *message= XMLString::transcode(toCatch.getMessage());
		cout<<"EXception message is :\n"<<message<<"\n";
		XMLString::release(&message);
		return -1;
	}
/*
	catch(const SAXParserException &toCatch){
		char *message = XMLString::transcode(toCatch.getMessage());
		cout<<"Exception message is :\n"<<message<<"\n";
		XMLString::release(&message);
		return -1;
	}
*/
	catch(...){
		cout<<"Unexpected Exception \n";
		return -1;
	}

	delete parser;
	delete errHandler;
	return 0;
}
