import FWCore.ParameterSet.Config as cms

process = cms.Process("copy")
process.load("FWCore.MessageLogger.MessageLogger_cfi")
#process.load("hbrun.HughFilter.HughFilter_cfi.py")
process.load("Configuration.StandardSequences.Services_cff")
process.load("Configuration.Geometry.GeometryIdeal_cff")
process.load('Configuration/StandardSequences/MagneticField_38T_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
process.load("Configuration.StandardSequences.Reconstruction_cff")
process.GlobalTag.globaltag = '80X_dataRun2_Prompt_v11'
process.MessageLogger.cerr.threshold = 'INFO'
process.MessageLogger.cerr.FwkReport.reportEvery = 1

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
  '/store/data/Run2016G/Charmonium/RAW/v1/000/280/385/00000/F06F46B7-FC76-E611-B182-02163E0140E1.root'
#	'/store/data/Run2016G/DoubleMuonLowMass/RAW/v1/000/280/349/00000/7CF9F3B1-FE75-E611-8120-FA163E1031EB.root'
# 'file:MYCOPY.root'
)
)

#process.source.eventsToProcess = cms.untracked.VEventRange (["280349:906100593"])
process.source.eventsToProcess = cms.untracked.VEventRange (["280385:3595209680"])

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)

process.HughFilter = cms.EDFilter("filterTheEvents",
	runsToKeep = cms.vint32(
		1,1
	),
	eventsToKeep= cms.vint32(
		35252,35534
	)

)
process.out = cms.OutputModule("PoolOutputModule",
#    verbose = cms.untracked.bool(False),
    fileName = cms.untracked.string('MYCOPY_2.root'),
 SelectEvents = cms.untracked.PSet(
    SelectEvents = cms.vstring("HughFilterSeq")
    )
)

process.HughFilterSeq = cms.Path(process.HughFilter)
process.outpath = cms.EndPath(process.out)



