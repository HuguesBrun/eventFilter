import FWCore.ParameterSet.Config as cms

process = cms.Process("copyy")
process.load("FWCore.MessageLogger.MessageLogger_cfi")
#process.load("hbrun.HughFilter.HughFilter_cfi.py")
process.load("Configuration.StandardSequences.Services_cff")
process.load("Configuration.Geometry.GeometryIdeal_cff")
process.load('Configuration/StandardSequences/MagneticField_38T_cff')
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.load("Configuration.StandardSequences.Reconstruction_cff")
process.GlobalTag.globaltag = 'PRE_P62_V10::All'
process.MessageLogger.cerr.threshold = 'INFO'
process.MessageLogger.cerr.FwkReport.reportEvery = 1

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
# '/store/group/comm_trigger/TriggerStudiesGroup/Skims/Top/SingleTop/SingleMu/pickevents_SingleTopMu_1_1_V4D.root'
 'file:MYCOPY.root'
)
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)

process.HughFilter = cms.EDFilter("filterTheEvents",
	runsToKeep = cms.vint32(
		203894, 203894
	),
	eventsToKeep= cms.vint32(
		78710089, 136304875
	)

)
process.out = cms.OutputModule("PoolOutputModule",
#    verbose = cms.untracked.bool(False),
    fileName = cms.untracked.string('MYCOPY.root'),
 SelectEvents = cms.untracked.PSet(
    SelectEvents = cms.vstring("HughFilterSeq")
    )
)

process.HughFilterSeq = cms.Path(process.HughFilter)
process.outpath = cms.EndPath(process.out)



