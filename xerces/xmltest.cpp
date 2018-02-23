#include <xercesc/util/PlatformUtils.hpp>

// Other include files, declarations, and non-Xerces-C++ initializations.
using namespace xercesc;
int main(int argc, char* argv[])
{
//  DOMPrint <test_data.xml>
  try {
    XMLPlatformUtils::Initialize();
  }
  catch (const XMLException& toCatch) {
    // Do your failure processing here
    return 1;
  }
  // Do your actual work with Xerces-C++ here.
  XMLPlatformUtils::Terminate();
  // Other terminations and cleanup.
  return 0;
}
