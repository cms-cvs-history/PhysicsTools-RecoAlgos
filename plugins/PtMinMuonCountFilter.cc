/* \class PtMinMuonCountFilter
 *
 * Filters events if at least N muons above 
 * a pt cut are present
 *
 * \author: Luca Lista, INFN
 *
 */
#include "FWCore/Framework/interface/MakerMacros.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "PhysicsTools/UtilAlgos/interface/ObjectCountFilter.h"
#include "PhysicsTools/UtilAlgos/interface/PtMinSelector.h"

typedef ObjectCountFilter<
          reco::MuonCollection, 
          PtMinSelector<reco::Muon>
        > PtMinMuonCountFilter;

DEFINE_FWK_MODULE( PtMinMuonCountFilter );
