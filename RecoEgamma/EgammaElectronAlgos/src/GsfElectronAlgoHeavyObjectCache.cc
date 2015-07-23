#include "RecoEgamma/EgammaElectronAlgos/interface/GsfElectronAlgoHeavyObjectCache.h"

namespace gsfAlgoHelpers {
  HeavyObjectCache::HeavyObjectCache(const edm::ParameterSet& conf) {
    // soft electron MVA
    SoftElectronMVAEstimator::Configuration sconfig;
    sconfig.vweightsfiles = 
      conf.getParameter<std::vector<std::string> >("SoftElecMVAFilesString");
    sElectronMVAEstimator.reset(new SoftElectronMVAEstimator(sconfig));
    // isolated electron MVA
    std::cout << "building iso ele mva" << std::endl;
    ElectronMVAEstimator::Configuration iconfig;
    iconfig.vweightsfiles  =
      conf.getParameter<std::vector<std::string> >("ElecMVAFilesString");
    iElectronMVAEstimator.reset(new ElectronMVAEstimator(iconfig));    
    std::cout << "built iso ele mva" << std::endl;
  }
}
