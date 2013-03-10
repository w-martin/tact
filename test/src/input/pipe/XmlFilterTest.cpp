/**
 * @file XmlFilterTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.2
 *
 * @section LICENSE
 *
 * This file is part of teflon.
 *
 * teflon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * teflon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with teflon.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "gtest/gtest.h"
#include "teflon/input/pipe/XmlFilter.h"
#include "teflon/input/corpus/text/TextCorpus.h"
#include "teflon/input/corpus/feature/FeatureCorpus.h"

/**
 * Tests XmlFilter.
 *
 */
class XmlFilterTest : public ::testing::Test {
protected:

  XmlFilterTest() {
    pipe = new XmlFilter();
  }

  virtual ~XmlFilterTest() {
    delete pipe;
  }
  XmlFilter * pipe;
};

/*
 * Tests whether the process method works correctly.
 *
 */
TEST_F(XmlFilterTest, ProcessExceptionTest) {
  auto_ptr< Corpus > corpus = auto_ptr< Corpus > (
                                new Corpus(".", DOCUMENT_TYPE_BASIC));
  EXPECT_THROW(pipe->pipe(corpus), IncompatibleCorpusException);

  corpus = auto_ptr< Corpus > (
             new Corpus(".", DOCUMENT_TYPE_FEATURE));
  EXPECT_THROW(pipe->pipe(corpus), IncompatibleCorpusException);
}

/*
 * Tests whether the process method works correctly.
 *
 */
TEST_F(XmlFilterTest, ProcessTest) {
  auto_ptr< Corpus > corpus =
    auto_ptr< Corpus > (new TextCorpus("."));

  auto_ptr< string > text = auto_ptr< string > (
                              new string("<tag> some text<tag 2><tag>><tag 3>text"));
  auto_ptr< Document > document =
    auto_ptr< Document > (new TextDocument("doc", text));
  corpus->addDocument(document);
  EXPECT_EQ(1, corpus->getSize());

  corpus = pipe->pipe(corpus);
  EXPECT_EQ(1, corpus->getSize());
  TextDocument const * const processedDocument =
    ((TextDocument *) corpus->getDocuments()->at(0));
  EXPECT_STREQ("  some text  > text",
               processedDocument->getText()->c_str());
}

/*
 * Tests whether the removeXml method work correctly.
 *
 */
TEST_F(XmlFilterTest, RemoveXmlTest) {
  string text = "<tag> some text<tag 2><tag>><tag 3>text";
  auto_ptr< string > processed = XmlFilter::removeXml(text);
  EXPECT_STREQ("  some text  > text", processed->c_str());
}
