/* \class PhotonCountFilter
 *
 * Filters events if at least N photons
 *
 * \author: Luca Lista, INFN
 *
 */
#include "FWCore/Framework/interface/MakerMacros.h"
#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "PhysicsTools/UtilAlgos/interface/ObjectCountFilter.h"

 typedef ObjectCountFilter<
           reco::PhotonCollection
         > PhotonCountFilter;

DEFINE_FWK_MODULE( PhotonCountFilter );