/**
   \file
   test file for FEDRawData library

   \author Stefano ARGIRO
   \version $Id$
   \date 28 Jun 2005
*/

static const char CVSId[] = "$Id$";

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
  raw::FEDRawData f;
  CPPUNIT_ASSERT(f.data_.size()==0);

  raw::FEDRawData f2(10);
  CPPUNIT_ASSERT(f2.data_.size()==size_t(10));
}

void testFEDRawData::testdata(){
  raw::FEDRawData f(3);
  f.data_[0]='a';
  f.data_[1]='b';
  f.data_[2]='c';
 

  const unsigned char * buf= f.data();
  
  CPPUNIT_ASSERT(buf[0] == 'a');
  CPPUNIT_ASSERT(buf[1] == 'b');
  CPPUNIT_ASSERT(buf[2] == 'c');
}
