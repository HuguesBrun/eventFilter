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

   int theRunNumber = iEvent.id().run();
   int theEventNumber = iEvent.id().event();
   int nbEvents = eventList_.size();
   int nbRuns = runList_.size();
   if (nbEvents != nbRuns) {
	std::cout << "nb of events different of the nb of runs !!!! " << std::endl;
	return false;
   }

   bool isGoodEvent=false;
   for (int i = 0 ; i < nbEvents ; i++){
   	if ((theRunNumber==runList_.at(i))&&(theEventNumber==eventList_.at(i))) isGoodEvent = true;
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
