#ifndef RecoAlgos_PhotonSelector_h
#define RecoAlgos_PhotonSelector_h
/** \class PhotonSelector
 *
 * selects a subset of an photon collection. Also clones
 * all referenced objects
 * 
 * \author Luca Lista, INFN
 *
 * \version $Revision: 1.2 $
 *
 * $Id: PhotonSelector.h,v 1.2 2006/09/22 10:46:43 llista Exp $
 *
 */

#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "PhysicsTools/UtilAlgos/interface/ObjectSelector.h"

namespace helper {
  struct PhotonCollectionStoreManager {
    PhotonCollectionStoreManager() :
      selPhotons_( new reco::PhotonCollection ),
      selSuperClusters_( new reco::SuperClusterCollection ) {
    }
    template<typename I>
    void cloneAndStore( const I & begin, const I & end, edm::Event & evt ) {
      using namespace reco;
      PhotonRefProd rPhotons = evt.template getRefBeforePut<PhotonCollection>();      
      SuperClusterRefProd rSuperClusters = evt.template getRefBeforePut<SuperClusterCollection>();      
      size_t idx = 0;
      for( I i = begin; i != end; ++ i ) {
	const Photon & ele = * * i;
	selPhotons_->push_back( Photon( ele ) );
	selPhotons_->back().setSuperCluster( SuperClusterRef( rSuperClusters, idx ++ ) );
	selSuperClusters_->push_back( SuperCluster( * ( ele.superCluster() ) ) );
      }
    }
    void put( edm::Event & evt ) {
      evt.put( selPhotons_ );
      evt.put( selSuperClusters_ );
    }
    bool empty() const { return selPhotons_->empty(); }
  private:
    std::auto_ptr<reco::PhotonCollection> selPhotons_;
    std::auto_ptr<reco::SuperClusterCollection> selSuperClusters_;
  };

  class PhotonSelectorBase : public edm::EDFilter {
  public:
    PhotonSelectorBase( const edm::ParameterSet & cfg ) {
      std::string alias( cfg.getParameter<std::string>( "@module_label" ) );
      produces<reco::PhotonCollection>().setBranchAlias( alias + "Photons" );
      produces<reco::SuperClusterCollection>().setBranchAlias( alias + "SuperClusters" );
    }
   };

  template<>
  struct CollectionStoreManager<reco::PhotonCollection> {
    typedef PhotonCollectionStoreManager type;
    typedef PhotonSelectorBase base;
  };
}

#endif
