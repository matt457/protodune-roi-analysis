// Get roi bin inclusion percentage from root hist
// Modify roi filename
#include <string>
#include <fstream>

{
    printf("ROI \n");
    TFile f2("protodune_results/protodune-data-check-roi22-v5.root");
    TIter next2(f2.GetListOfKeys());
    TKey *key2;
    float mytot1 = 0.0;
    float mytot2 = 0.0;
    while ((key2=(TKey*)next2())) 
    {
        string key_name = key2->GetName();
        // calculate percent of bins included with ROI
        if (key_name.find("roi") != string::npos)
        {
            printf("key: %s \n", key2->GetName());
            TH2F *roi = (TH2F*)f2.Get(key2->GetName()); // 2D histogram of floats

            int n_bins_x = roi->GetNbinsX();
            int n_bins_y = roi->GetNbinsY();
            float n_bins_tot = n_bins_x * n_bins_y;
            float n_bins_inc = 0.0;
            for (int xbin=1; xbin<=n_bins_x; xbin++)
            {
                for (int ybin=1; ybin<=n_bins_y; ybin++)
                {
                    // get bin content
                    int bin_id = roi->GetBin(xbin, ybin);
                    float bin_content = roi->GetBinContent(bin_id);

                    if (bin_content != 0.0){
                        n_bins_inc += 1;
                    }
                }
            }

            mytot1 += n_bins_inc;
            mytot2 += n_bins_tot;

        }
    }

    //printf("mytot1: %f \n", mytot1);
    //printf("mytot2: %f \n", mytot2);
    printf("ROI bins included: %f \n", mytot1/mytot2);
}


