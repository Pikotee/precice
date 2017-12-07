#include "io/config/ExportConfiguration.hpp"
#include "testing/Testing.hpp"
#include "utils/Globals.hpp"
#include "xml/XMLTag.hpp"

BOOST_AUTO_TEST_SUITE(IOTests)

using namespace precice;

BOOST_AUTO_TEST_CASE(Configuration)
{
  using xml::XMLTag;
  XMLTag tag = xml::getRootTag();
  {
    io::ExportConfiguration config(tag);
    xml::configure(tag, utils::getPathToSources() + "/io/boosttests/config1.xml");
    BOOST_TEST(config.exportContexts().size() == 1);
    const io::ExportContext &context = config.exportContexts().front();
    BOOST_TEST(context.type == "vtk");
    BOOST_TEST(context.timestepInterval == 10);
    BOOST_TEST(context.triggerSolverPlot);
  }
  {
    tag.clear();
    io::ExportConfiguration config(tag);
    xml::configure(tag, utils::getPathToSources() + "/io/boosttests/config2.xml");
    BOOST_TEST(config.exportContexts().size() == 1);
    const io::ExportContext &context = config.exportContexts().front();
    BOOST_TEST(context.type == "vtk");
    BOOST_TEST(context.timestepInterval == 1);
    BOOST_TEST(context.location == "somepath");
    BOOST_TEST(not context.triggerSolverPlot);
  }
  {
    tag.clear();
    io::ExportConfiguration config(tag);
    xml::configure(tag, utils::getPathToSources() + "/io/boosttests/config3.xml");
    BOOST_TEST(config.exportContexts().size() == 1);
    const io::ExportContext &context = config.exportContexts().front();
    BOOST_TEST(context.type == "vrml");
    BOOST_TEST(context.timestepInterval == 1);
    BOOST_TEST(context.location == "");
    BOOST_TEST(not context.triggerSolverPlot);
  }
}

BOOST_AUTO_TEST_SUITE_END() // IOTests
