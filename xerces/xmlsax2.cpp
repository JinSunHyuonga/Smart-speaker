    #include <xercesc/sax2/SAX2XMLReader.hpp>
    #include <xercesc/sax2/XMLReaderFactory.hpp>
    #include <xercesc/sax2/DefaultHandler.hpp>
    #include <xercesc/util/XMLString.hpp>

    #include <iostream>

    using namespace std;
    using namespace xercesc;

    int main (int argc, char* args[]) {

        try {
            XMLPlatformUtils::Initialize();
        }
        catch (const XMLException& toCatch) {
            char* message = XMLString::transcode(toCatch.getMessage());
            cout << "Error during initialization! :\n";
            cout << "Exception message is: \n"
                 << message << "\n";
            XMLString::release(&message);
            return 1;
        }

        char* xmlFile = "test_data.xml";
        SAX2XMLReader* parser = XMLReaderFactory::createXMLReader();
        parser->setFeature(XMLUni::fgSAX2CoreValidation, true);
        parser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);   // optional

        DefaultHandler* defaultHandler = new DefaultHandler();
        parser->setContentHandler(defaultHandler);
        parser->setErrorHandler(defaultHandler);

        try {
            parser->parse(xmlFile);
        }
        catch (const XMLException& toCatch) {
            char* message = XMLString::transcode(toCatch.getMessage());
            cout << "Exception message is: \n"
                 << message << "\n";
            XMLString::release(&message);
            return -1;
        }
        catch (const SAXParseException& toCatch) {
            char* message = XMLString::transcode(toCatch.getMessage());
            cout << "Exception message is: \n"
                 << message << "\n";
            XMLString::release(&message);
            return -1;
        }
        catch (...) {
            cout << "Unexpected Exception \n" ;
            return -1;
        }

        delete parser;
        delete defaultHandler;
        return 0;
	}
