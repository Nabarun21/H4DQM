#ifndef PLOT_TOOLS
#define PLOT_TOOLS

#include <TStyle.h>
#include <TROOT.h>
#include <TColor.h>
#include <TCanvas.h>
#include <TH1.h>
#include <TH2.h>
#include <TGraph.h>
#include <TRandom.h>
#include <TChain.h>
#include <TString.h>

#include <Event.hpp>

#define nPlanesHodo 4
#define nFibersHodo 64

#define nPlanesSmallHodo 2
#define nFibersSmallHodo 8


class plotterTools{

public:

  plotterTools (const char * filename, const char * outfname, const char * outdname);



  TChain* inputTree_;
  TFile* inputFile_;
  TFile* outputFile_;
  TString outputDir_;

  TString module_, group_;
  int historyStep_;//set the step of events for history plots

  treeStructData treeStruct_;

  std::vector<int> fiberOrderA;
  std::vector<int> fiberOrderB;
  std::map<TString,TObject*> outObjects_;
  std::map<TString,TString> plotShortNames_;
  std::map<TString,TString> plotLongNames_;
  std::vector<float> variables_;//<value,dimension>
  std::map<TString,float*> variablesMap_;
  std::map<TString,int> variablesIterator_;
  std::map<TString,std::vector<float> > variablesContainer_;
  std::map<TString,TString > variablesContainerTitles_;


  //fibers
  bool fibersOn_[nPlanesHodo][nFibersHodo];
  bool fibersOnSmall_[nPlanesSmallHodo][nFibersSmallHodo];

  //tdc readings
  static const UInt_t MaxTdcChannels = 4;
  std::vector<UInt_t> tdc_readings[MaxTdcChannels];

  void fillObjects();
  void initHodo();
  void initTdc();
  void fillFiberOrder();
  void set_plot_blue ();
  void set_palette_fancy ();
  void setPlotsFormat ();
  void plotMe (TH1F * histo);
  void plotMe (TH2F * histo);
  void plotMe (TGraph * graph, const TString & name);
  void setAxisTitles (TH1 * histo, const TString  xTitle, const TString  yTitle);
  void setAxisTitles (TH2 * histo, const TString  xTitle, const TString  yTitle);
  void setAxisTitles (TGraph * graph, const TString  xTitle, const TString  yTitle);
  void readInputTree ();
  void Loop();
  void saveHistos();
  void plotHistos();
  void printHistos();
  void bookPlotsScaler (int nBinsHistory);
  void bookPlotsHodo (int nBinsHistory);
  void bookPlotsSmallHodo (int nBinsHistory);
  void bookPlotsDAQStatus (int nBinsHistory);
  void bookPlotsTDC(int nBinsHistory);
  void bookCombinedPlots ();
  TGraph* bookGraph (TString name, int nPoints, TString type, TString group, TString module);
  void setGroup(TString group);
  void setModule(TString module);
  void setStepHistoryPlots(int n);
  int getTreeEntries();
  int getStepHistoryPlots();
  void FillPlot(TString name, int point, float X);//TGraph
  void FillPlot(TString name, bool is2D=false,int varDim=1);//TH1F
  TGraph * addPlot(TString name,int nPoints,TString type, TString group, TString module);//TGraph
  TH1F * addPlot(TString name,int nBinsX, float xMin, float xMax, TString type, TString group, TString module, int varDim=1);//TH1F
  TH2F * addPlot (TString name,int nBinsX, float xMin, float xMax, int nBinsY, float yMin, float yMax, TString xTitle, TString yTitle, TString type, TString group, TString module);//TH2F
  void addPlotCombined(TString name, TString name1, TString name2,TString type, TString group , TString module);
  TH1F* bookHisto(TString name,int nBinsX,float xMin, float xMax, TString type, TString group, TString module);
  TH2F* bookHisto2D(TString name,int nBinsX,float xMin, float xMax,int nBinsY, float yMin, float yMax,TString xTitle, TString yTitle, TString type, TString group, TString module);
  TH2F* bookHistoCombined(TString name,TString name1, TString name2);
  void initVariable(TString name, int varDim=1);
  void computeVariable(TString name, int varDim=1);
  pair<int, string> execute (const string & command);

  //fibers
  int findPosition(std::vector<int>* fiberVec, int n);

};

#endif
