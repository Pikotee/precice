#ifndef PRECICE_MESH_MESHCONFIGURATION_HPP_
#define PRECICE_MESH_MESHCONFIGURATION_HPP_

#include "mesh/SharedPointer.hpp"
#include "utils/Helpers.hpp"
#include "logging/Logger.hpp"
#include "xml/XMLTag.hpp"
#include <vector>
#include <list>
#include <map>
#include <string>

namespace precice {
  namespace mesh {
    class DataConfiguration;
  }
}

// ----------------------------------------------------------- CLASS DEFINITION

namespace precice {
namespace mesh {

class MeshConfiguration : public utils::XMLTag::Listener
{
public:

  // @brief Name of the XML Tag holding the mesh configuration.
  //static const std::string& getTag();

  /**
   * @brief Constructor, takes a valid data configuration as argument.
   */
  MeshConfiguration (
    utils::XMLTag&       parent,
    PtrDataConfiguration config );

  void setDimensions ( int dimensions );

  /**
   * @brief Parses the XML information to build up the mesh configuration.
   */
  //bool parseSubtag ( utils::XMLTag::XMLReader* xmlReader );

  /**
   * @brief Has to be called after parsing all mesh tags.
   *
   * To separate the sub ID setting from the setting of the main mesh IDs makes
   * it possible to have all main IDs in a continously increasing sequence.
   */
  void setMeshSubIDs();

  /**
   * @brief Returns true, if the configuration has taken place and is valid.
   */
  //bool isValid() const;

  /**
   * @brief Returns all configured meshes.
   */
  const std::vector<PtrMesh>& meshes() const;

  /**
   * @brief Returns all configured meshes.
   */
  std::vector<PtrMesh>& meshes();

  /**
   * @brief Returns the configured mesh with given name, or NULL.
   */
  mesh::PtrMesh getMesh ( const std::string& meshName ) const;

  virtual void xmlTagCallback ( utils::XMLTag& callingTag );

  virtual void xmlEndTagCallback ( utils::XMLTag& callingTag );

  const PtrDataConfiguration& getDataConfiguration() const;

  void addMesh ( const mesh::PtrMesh& mesh );

  std::map<std::string, std::vector<std::string> >& getNeededMeshes(){
    return _neededMeshes;
  }

  void addNeededMesh(
    const std::string& participant,
    const std::string& mesh);

private:

  // @brief Logging device.
  static logging::Logger _log;


  const std::string TAG;
  const std::string ATTR_NAME;
  const std::string ATTR_FLIP_NORMALS;
  const std::string TAG_DATA;
  const std::string TAG_SUB_ID;
  const std::string ATTR_SIDE_INDEX;

  int _dimensions;

  // @brief Set to true, if configuration has taken place and is valid.
  //bool _isValid;

  // @brief Data configuration.
  PtrDataConfiguration _dataConfig;

  // @brief Configured meshes.
  std::vector<PtrMesh> _meshes;

  bool _setMeshSubIDs;

  std::vector<std::list<std::string> > _meshSubIDs;

  // @brief to check later if all meshes that any coupling scheme needs are actually used by the participants
  std::map<std::string,std::vector<std::string> > _neededMeshes;
};

}} // namespace precice, mesh

#endif /* PRECICE_MESH_MESHCONFIGURATION_HPP_ */
