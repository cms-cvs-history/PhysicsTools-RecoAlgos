/* \class EtMinCaloJetSelector
 *
 * selects calo-jet above a minumum Et cut
 *
 * \author: Luca Lista, INFN
 *
 */
#include "FWCore/Framework/interface/MakerMacros.h"
#include "PhysicsTools/UtilAlgos/interface/EtMinSelector.h"
#include "PhysicsTools/UtilAlgos/interface/SingleObjectSelector.h"
#include "DataFormats/JetReco/interface/CaloJet.h"

 typedef SingleObjectSelector<
           reco::CaloJetCollection, 
           EtMinSelector<reco::CaloJet> 
         > EtMinCaloJetSelector;

DEFINE_FWK_MODULE( EtMinCaloJetSelector );
