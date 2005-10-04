/**
   \file
   test file for FEDRawData library

   \author Stefano ARGIRO
   \version $Id: FEDRawData_t.cc,v 1.2 2005/09/30 08:13:54 namapane Exp $
   \date 28 Jun 2005
*/

static const char CVSId[] = "$Id: FEDRawData_t.cc,v 1.2 2005/09/30 08:13:54 namapane Exp $";

#include <cppunit/extensions/HelperMacros.h>
#include <DataFormats/FEDRawData/interface/FEDRawData.h>

#include <iostream>
class testFEDRawData: public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(testFEDRawData);

  CPPUNIT_TEST(testCtor);
  CPPUNIT_TEST(testdata);
 
  CPPUNIT_TEST_SUITE_END();

public:


  void setUp(){}
  void tearDown(){}  
  void testCtor();
  void testdata(); 
 
}; 

///registration of the test so that the runner can find it
CPPUNIT_TEST_SUITE_REGISTRATION(testFEDRawData);


void testFEDRawData::testCtor(){
  FEDRawData f;
  CPPUNIT_ASSERT(f.size()==0);

  FEDRawData f2(10);
  CPPUNIT_ASSERT(f2.size()==size_t(10));
}

void testFEDRawData::testdata(){
  FEDRawData f(3);
  f.data()[0]='a';
  f.data()[1]='b';
  f.data()[2]='c';
 

  const unsigned char * buf= f.data();
  
  CPPUNIT_ASSERT(buf[0] == 'a');
  CPPUNIT_ASSERT(buf[1] == 'b');
  CPPUNIT_ASSERT(buf[2] == 'c');
}
