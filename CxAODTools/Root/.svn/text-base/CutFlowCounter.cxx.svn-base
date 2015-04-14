#include "CxAODTools/CutFlowCounter.h"

void CutFlowCounter::setName( TString name ) {

  //std::cout<<" cutFlow name: "<<m_name<<std::endl;

  m_name = name;
  m_doStopCount = 0;

}


// Set the name of cut one by one to setup the cutflowInfor map 
void CutFlowCounter::setCutFlow( int priority, TString cutName ) {

  //std::cout<<" priority "<<priority<<" cut name: "<<cutName<<std::endl;

  Counter cutInfor;
  cutInfor.priority = priority;
  cutInfor.count    = 0;
  cutInfor.sumOfWeight   = 0;

  m_cutFlowInfor[cutName.Data()] = cutInfor;
  //m_cutFlowInfor.insert ( std::pair<TString, Counter>( cutName, cutInfor ) );

  //std::cout<<" 0 ncutFlow: "<<m_cutFlowInfor.size()<<std::endl;
}

// Count the number of entries and weights passing the cut
void CutFlowCounter::count( int priority, TString cutName, double weight ) {

  if( m_doStopCount ) return ;

  if( m_cutFlowInfor.find( cutName.Data() )==m_cutFlowInfor.end() ) {
    setCutFlow( priority, cutName ) ;
  }

  m_cutFlowInfor[cutName.Data() ].count +=1;
  m_cutFlowInfor[cutName.Data() ].sumOfWeight +=weight;

}

// Don't count in some case, e.g. systematics variations and etc
void CutFlowCounter::doStopCount( bool doStop ) {
  m_doStopCount = doStop;
}

// Don't count in some case, e.g. systematics variations and etc
TH1D * CutFlowCounter::getCutFlow() {
  int  ncutFlow = m_cutFlowInfor.size();

  //std::cout<<" ncutFlow: "<<ncutFlow<<std::endl;

  TH1D * m_h_cutFlow = new TH1D( m_name, m_name, ncutFlow, 0, ncutFlow );
  //m_h_cutFlow ->Print();

  std::vector< std::pair< std::string, Counter > >  vectorToOrder;

  std::map<std::string, Counter>::iterator it=m_cutFlowInfor.begin();
  for( ; it!=m_cutFlowInfor.end(); it++ ) {
    vectorToOrder.push_back( std::make_pair(it->first, it->second) );
  }

  //std::sort(vectorToOrder.begin(), vectorToOrder.end(), ComparePriority );

  for( int idx=0; idx<vectorToOrder.size(); idx++ ) {
    std::pair< std::string, Counter > element = vectorToOrder[idx];
    //std::cout<<" order 0: "<< element.second.priority<<" idx: "<< idx <<std::endl;
  }

  for( int idx0=0; idx0<vectorToOrder.size(); idx0++ ) {

    int tmpMin_idx = idx0;

    for( int idx1=idx0+1; idx1<vectorToOrder.size(); idx1++ ) {

      //std::cout<<" 1: "<< vectorToOrder[tmpMin_idx].second.priority<<" 2: "<< vectorToOrder[idx1].second.priority <<std::endl;

      if( vectorToOrder[idx1].second.priority < vectorToOrder[tmpMin_idx].second.priority ) {
        tmpMin_idx = idx1;
      }

    }

    if(tmpMin_idx!=idx0) {
      std::pair< std::string, Counter > tmpelement = vectorToOrder[idx0];
      vectorToOrder[idx0] = vectorToOrder[tmpMin_idx];
      vectorToOrder[tmpMin_idx] = tmpelement;
    }

  }

  for( int idx=0; idx<vectorToOrder.size(); idx++ ) {
    std::pair< std::string, Counter > element = vectorToOrder[idx];
    //std::cout<<" order 2: "<< element.second.priority<<" idx: "<< idx <<std::endl;
  }

  for( int idx=0; idx<vectorToOrder.size(); idx++ ) {

    std::pair< std::string, Counter > element = vectorToOrder[idx];

    //std::cout<<" order: "<< element.second.priority<<" idx: "<< idx <<std::endl;

    m_h_cutFlow->GetXaxis()->SetBinLabel( idx+1 , element.first.c_str() );
    m_h_cutFlow->SetBinContent( idx+1 , element.second.sumOfWeight );
  }

  return m_h_cutFlow;
}
