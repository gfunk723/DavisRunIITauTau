// -*- C++ -*-
//
// Package:    CustomPatMuonProducer
// Class:      CustomPatMuonProducer
//
/**\class CustomPatMuonProducer CustomPatMuonProducer.cc TEMP/CustomPatMuonProducer/src/CustomPatMuonProducer.cc

Description: [one line class summary]

Implementation:
[Notes on implementation]
*/
//
// Original Author:  shalhout shalhout
//         Created:  Mon Jul 14 12:35:16 CDT 2014
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

// needed by ntuple muon producer
#include <vector>
#include <iostream>
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Lepton.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "TLorentzVector.h"
#include "DataFormats/Math/interface/Vector3D.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "Math/GenVector/VectorUtil.h"
#include "DataFormats/PatCandidates/interface/PFParticle.h"
#include "DataFormats/PatCandidates/interface/TriggerEvent.h"
#include "DataFormats/Common/interface/ValueMap.h"
#include "DavisRunIITauTau/CustomPatCollectionProducers/interface/LeptonRelativeIsolationTool.h"
#include "DavisRunIITauTau/CustomPatCollectionProducers/interface/MuonClones.h"


#include "DataFormats/Math/interface/deltaR.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"


typedef math::XYZTLorentzVector LorentzVector;
using namespace std;
using namespace edm;
using namespace pat;
typedef std::vector<pat::Muon> PatMuonCollection;
typedef std::vector<edm::InputTag> vInputTag;



//
// class declaration
//

class CustomPatMuonProducer : public edm::EDProducer {
public:
  explicit CustomPatMuonProducer(const edm::ParameterSet&);
  ~CustomPatMuonProducer();

  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

private:
  virtual void beginJob() ;
  virtual void produce(edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  virtual void beginRun(edm::Run&, edm::EventSetup const&);
  virtual void endRun(edm::Run&, edm::EventSetup const&);
  virtual void beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);
  virtual void endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);

  // ----------member data ---------------------------
  edm::InputTag muonSrc_;
  edm::EDGetTokenT<edm::View< pat::Muon > > muonToken_;


  string NAME_;

  edm::InputTag vertexSrc_;
  edm::EDGetTokenT< edm::View<reco::Vertex> > vertexToken_;

  edm::EDGetTokenT<edm::TriggerResults> triggerBitSrc_;
  edm::EDGetTokenT<pat::PackedTriggerPrescales> triggerPreScaleSrc_;
  edm::EDGetTokenT<pat::TriggerObjectStandAloneCollection> triggerObjectSrc_;

  vInputTag rhoSources_;
  std::vector < edm::EDGetTokenT<double> > rhoTokens_;


};

//
// constants, enums and typedefs
//


//
// static data member definitions
//

//
// constructors and destructor
//
CustomPatMuonProducer::CustomPatMuonProducer(const edm::ParameterSet& iConfig):
muonSrc_(iConfig.getParameter<edm::InputTag>("muonSrc" )),
NAME_(iConfig.getParameter<string>("NAME" )),
vertexSrc_(iConfig.getParameter<edm::InputTag>("vertexSrc" )),
triggerBitSrc_(consumes<edm::TriggerResults>(iConfig.getParameter<edm::InputTag>("triggerBitSrc"))),
triggerPreScaleSrc_(consumes<pat::PackedTriggerPrescales>(iConfig.getParameter<edm::InputTag>("triggerPreScaleSrc"))),
triggerObjectSrc_(consumes<pat::TriggerObjectStandAloneCollection>(iConfig.getParameter<edm::InputTag>("triggerObjectSrc"))),
rhoSources_(iConfig.getParameter<vInputTag>("rhoSources" ))
{

  produces<PatMuonCollection>(NAME_).setBranchAlias(NAME_);


  muonToken_ = consumes< edm::View<pat::Muon> >(muonSrc_);

  vertexToken_ = consumes< edm::View<reco::Vertex> >(vertexSrc_);

  for(vInputTag::const_iterator it=rhoSources_.begin();it!=rhoSources_.end();it++) 
  {
    rhoTokens_.push_back( consumes<double >( *it ) );
  }



  //register your products
  /* Examples
  produces<ExampleData2>();

  //if do put with a label
  produces<ExampleData2>("label");

  //if you want to put into the Run
  produces<ExampleData2,InRun>();
  */
  //now do what ever other initialization is needed

}


CustomPatMuonProducer::~CustomPatMuonProducer()
{

  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
CustomPatMuonProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{



  // get vertex collection
  edm::Handle<edm::View<reco::Vertex> > vertices;
  iEvent.getByToken(vertexToken_,vertices);
  const reco::Vertex & first_vertex = vertices->at(0);

  // get muon collection
  edm::Handle<edm::View<pat::Muon> > muons;
  iEvent.getByToken(muonToken_,muons);




  // get the rho variants

  std::vector<std::string> rhoNames;
  std::vector<double> rhos;


  for(std::size_t r = 0; r<rhoTokens_.size(); ++r)
  {
    edm::Handle<double> arho;
    iEvent.getByToken(rhoTokens_[r],arho);

    rhoNames.push_back(rhoSources_[r].label());
    rhos.push_back(*arho);
    //std::cout<<rhoSources_[r].label()<<" "<<*arho<<std::endl;

  }





// get trigger-related collections

    edm::Handle<edm::TriggerResults> triggerBits;
    edm::Handle<pat::TriggerObjectStandAloneCollection> triggerObjects;
    edm::Handle<pat::PackedTriggerPrescales> triggerPreScales;

    iEvent.getByToken(triggerBitSrc_, triggerBits);
    iEvent.getByToken(triggerObjectSrc_, triggerObjects);
    iEvent.getByToken(triggerPreScaleSrc_, triggerPreScales);

    const edm::TriggerNames &names = iEvent.triggerNames(*triggerBits);


  muonClones mu(muons,first_vertex,triggerBits,triggerObjects,triggerPreScales,names,
                    rhoNames,rhos);  


  auto_ptr<PatMuonCollection> storedMuons (new PatMuonCollection);


  for (std::size_t i = 0; i<muons->size(); i++)
  {




    const pat::Muon & muonToStore = mu.clones[i];
    storedMuons->push_back(muonToStore);

    // std::cout<<" ------> muon with pt = "<<muonToStore.p4().Pt()<<std::endl;
    // std::cout<<" -------------> relIsol = "<<muonToStore.userFloat("relIso")<<std::endl;
    // std::cout<<" -------------> dxy = "<<muonToStore.userFloat("dxy")<<std::endl;
    // std::cout<<" -------------> dz = "<<muonToStore.userFloat("dz")<<std::endl;

    // dump userFloats -- test start
    // for (std::size_t ii = 0; ii < muonToStore.userFloatNames().size(); ii ++ )
    // {
    //     std::cout<<"muon "<<i<<" "<<muonToStore.userFloatNames().at(ii)<<" "<<muonToStore.userFloat(muonToStore.userFloatNames().at(ii))<<"\n";
    // }
    // dump userFloats -- test end


  }

  // add the muons to the event output
  iEvent.put(storedMuons,NAME_);


}

// ------------ method called once each job just before starting event loop  ------------
void
CustomPatMuonProducer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void
CustomPatMuonProducer::endJob() {
}

// ------------ method called when starting to processes a run  ------------
void
CustomPatMuonProducer::beginRun(edm::Run&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void
CustomPatMuonProducer::endRun(edm::Run&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void
CustomPatMuonProducer::beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void
CustomPatMuonProducer::endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
CustomPatMuonProducer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(CustomPatMuonProducer);
