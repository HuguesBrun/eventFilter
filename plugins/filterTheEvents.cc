// -*- C++ -*-
//
// Package:    hugues/filterTheEvents
// Class:      filterTheEvents
// 
/**\class filterTheEvents filterTheEvents.cc hugues/filterTheEvents/plugins/filterTheEvents.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Hugues Louis Brun
//         Created:  Fri, 31 Jan 2014 08:32:29 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDFilter.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

//
// class declaration
//

class filterTheEvents : public edm::EDFilter {
   public:
      explicit filterTheEvents(const edm::ParameterSet&);
      ~filterTheEvents();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

   private:
      virtual void beginJob() override;
      virtual bool filter(edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;
      
      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

      // ----------member data ---------------------------
      //
      std::vector<int> eventList_;
      std::vector<int> runList_;
      
      

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
filterTheEvents::filterTheEvents(const edm::ParameterSet& iConfig)
{
   //now do what ever initialization is needed
   eventList_ = iConfig.getParameter<std::vector <int> >("eventsToKeep");
   runList_= iConfig.getParameter<std::vector <int> >("runsToKeep");
}


filterTheEvents::~filterTheEvents()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called on each new Event  ------------
bool
filterTheEvents::filter(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

   //int theRunNumber = iEvent.id().run();
   int theEventNumber = iEvent.id().event();
   int nbEvents = eventList_.size();
//   int nbRuns = runList_.size();
  /* if (nbEvents != nbRuns) {
	std::cout << "nb of events different of the nb of runs !!!! " << std::endl;
	return false;
   }*/

   //int listEvents[320] = {35252,35534,35625,76581,76645,9463,28823,29107,29566,90613,90665,26484,61477,62068,62181,63130,36117,36668,39933,40027,10527,10844,10926,21869,97281,97472,97565,97643,71824,71935,72054,72336,94278,94730,52421,73615,74189,38131,38197,56716,34022,34079,34140,34299,35208,35346,35385,35392,35410,35446,35450,35455,35486,35527,35535,35538,35552,35613,35753,35785,35801,35957,71485,71502,71538,71549,71596,71605,71625,71669,71707,71764,71767,71786,71788,71791,76469,76508,76527,76668,34167,34194,71660,76681,76781,28909,29383,92845,93130,26407,61567,61935,62174,63256,36045,36095,36292,36745,60613,60791,10789,97536,72036,26396,73575,73631,74164,74170,38104,56612,78398,79156,52978,53206,56409,68891,69000,69074,69112,25080,34029,34066,34102,34253,34352,34356,34379,35489,35498,35528,35564,35599,35670,35779,35959,35967,71410,71710,71739,71756,76446,76506,76869,77142,9258,9457,29086,29194,29215,29298,29498,29599,90494,92740,92813,92961,93040,93095,26476,26600,35217,76407,76466,76803,76839,28824,28834,28908,29063,29078,29516,29567,90678,90727,93120,26439,71397,62003,63312,39978,60799,10552,10605,97242,97355,97468,97900,66905,71946,94223,94349,51949,52429,73895,73927,37838,37970,38084,56473,68645,34086,34141,34170,34177,34211,34264,34304,34315,35263,35296,35581,35584,35627,35672,35681,35682,35729,35734,35744,35841,35902,35943,35985,35992,71448,71581,71588,71775,76464,76472,76486,76494,76765,76776,76836,76883,76916,76960,77007,77011,34212,35832,76434,76461,76656,28861,93055,71216,61705,63253,63285,36373,36514,36562,36618,40438,40452,60648,97556,97600,97723,66741,71990,72372,94446,26190,26327,26377,52316,52519,73685,73742,74122,57352,78618,78729,79022,79145,53086,53320,34022,34079,34140,34299,35208,35252,35346,35385,35392,35410,35446,35450,35455,35486,35527,35534,35535,35538,35552,35613,35625,35753,35785,35801,35957,71485,71502,71538,71549,71596,71605,71625,71669,71707,71764,71767,71786,71788,71791,76469};

   bool isGoodEvent=false;
   for (int i = 0 ; i < nbEvents; i++){
   	if ((theEventNumber==eventList_.at(i))) isGoodEvent = true;
   }
   if (isGoodEvent) std::cout << "coucou on passe" << std::endl;
   return isGoodEvent;

}

// ------------ method called once each job just before starting event loop  ------------
void 
filterTheEvents::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
filterTheEvents::endJob() {
}

// ------------ method called when starting to processes a run  ------------
/*
void
filterTheEvents::beginRun(edm::Run const&, edm::EventSetup const&)
{ 
}
*/
 
// ------------ method called when ending the processing of a run  ------------
/*
void
filterTheEvents::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/
 
// ------------ method called when starting to processes a luminosity block  ------------
/*
void
filterTheEvents::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/
 
// ------------ method called when ending the processing of a luminosity block  ------------
/*
void
filterTheEvents::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/
 
// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
filterTheEvents::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}
//define this as a plug-in
DEFINE_FWK_MODULE(filterTheEvents);
