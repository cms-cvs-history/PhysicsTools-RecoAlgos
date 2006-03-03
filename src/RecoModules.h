#ifndef RecoAlgos_RecoModules_h
#define RecoAlgos_RecoModules_h
// $Id$
#include "PhysicsTools/UtilAlgos/interface/Merger.h"
#include "DataFormats/Common/interface/CopyPolicy.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/EGammaReco/interface/Electron.h"
#include "DataFormats/EGammaReco/interface/Photon.h"

namespace recomodules {
  /// Framework module to merge an arbitray number of reco::TrackCollection
  typedef Merger<reco::TrackCollection,    edm::CopyPolicy<reco::Track> >    TrackMerger;
  /// Framework module to merge an arbitray number of reco::MuonCollection
  typedef Merger<reco::MuonCollection,     edm::CopyPolicy<reco::Muon> >     MuonMerger;
  /// Framework module to merge an arbitray number of reco::ElectronCollection
  typedef Merger<reco::ElectronCollection, edm::CopyPolicy<reco::Electron> > ElectronMerger;
  /// Framework module to merge an arbitray number of reco::PhotonCollection
  typedef Merger<reco::PhotonCollection,   edm::CopyPolicy<reco::Photon> >   PhotonMerger;
}

#endif