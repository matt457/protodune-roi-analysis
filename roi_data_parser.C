// Parse root histogram data to csv
// Run on root: protodune_results/protodune-data-check-roi.root
#include <string>
#include <fstream>

{
    printf("Original \n");
    TFile f1("protodune_results/protodune-data-check-orig-5.root");
    TIter next1(f1.GetListOfKeys());
    TKey *key1;
    while ((key1=(TKey*)next1())) 
    {
        string key_name = key1->GetName();
        if (key_name.find("gauss") != string::npos)
        {
            printf("key: %s \n", key1->GetName());
            TH2F *gauss = (TH2F*)f1.Get(key1->GetName()); // 2D histogram of floats

            // setup csv
            std::ofstream myfile;
            string outfile_name = "protodune_results/" + key_name + "_orig.csv";
            myfile.open (outfile_name);

            // write axis ranges to csv
            Double_t xmax = gauss->GetXaxis()->GetXmax(); 
            Double_t xmin = gauss->GetXaxis()->GetXmin(); 
            Double_t ymax = gauss->GetYaxis()->GetXmax(); 
            Double_t ymin = gauss->GetYaxis()->GetXmin(); 
            myfile << xmin << "," << ymin << "," << 0 << "\n";
            myfile << xmax << "," << ymax << "," << 0 << "\n";

            // loop through each bin in hist and save bin contents to csv
            int n_bins_x = gauss->GetNbinsX();
            int n_bins_y = gauss->GetNbinsY();
            for (int xbin=1; xbin<=n_bins_x; xbin++)
            {
                for (int ybin=1; ybin<=n_bins_y; ybin++)
                {
                    // get bin content
                    int bin_id = gauss->GetBin(xbin, ybin);
                    float bin_content = gauss->GetBinContent(bin_id);

                    // save to csv
                    if (bin_content != 0.0){
                        myfile << xbin << "," << ybin << "," << bin_content << "\n";
                    }
                }
            }

            myfile.close();

        }
    }

    printf("ROI \n");
    TFile f2("protodune_results/protodune-data-check-roi-5.root");
    TIter next2(f2.GetListOfKeys());
    TKey *key2;
    float mytot1 = 0.0;
    float mytot2 = 0.0;
    while ((key2=(TKey*)next2())) 
    {
        string key_name = key2->GetName();
        if (key_name.find("gauss") != string::npos)
        {
            printf("key: %s \n", key2->GetName());
            TH2F *gauss = (TH2F*)f2.Get(key2->GetName()); // 2D histogram of floats

            // setup csv
            std::ofstream myfile;
            string outfile_name = "protodune_results/" + key_name + "_roi.csv";
            myfile.open (outfile_name);

            // write axis ranges to csv
            Double_t xmax = gauss->GetXaxis()->GetXmax(); 
            Double_t xmin = gauss->GetXaxis()->GetXmin(); 
            Double_t ymax = gauss->GetYaxis()->GetXmax(); 
            Double_t ymin = gauss->GetYaxis()->GetXmin(); 
            myfile << xmin << "," << ymin << "," << 0 << "\n";
            myfile << xmax << "," << ymax << "," << 0 << "\n";

            // loop through each bin in hist and save bin contents to csv
            int n_bins_x = gauss->GetNbinsX();
            int n_bins_y = gauss->GetNbinsY();
            for (int xbin=1; xbin<=n_bins_x; xbin++)
            {
                for (int ybin=1; ybin<=n_bins_y; ybin++)
                {
                    // get bin content
                    int bin_id = gauss->GetBin(xbin, ybin);
                    float bin_content = gauss->GetBinContent(bin_id);

                    // save to csv
                    if (bin_content != 0.0){
                        myfile << xbin << "," << ybin << "," << bin_content << "\n";
                    }
                }
            }

            myfile.close();

        }

        // calculate percent of bins included with ROI
        // else if (key_name.find("roi") != string::npos)
        // {
        //     printf("key: %s \n", key2->GetName());
        //     TH2F *roi = (TH2F*)f2.Get(key2->GetName()); // 2D histogram of floats

        //     int n_bins_x = roi->GetNbinsX();
        //     int n_bins_y = roi->GetNbinsY();
        //     float n_bins_tot = n_bins_x * n_bins_y;
        //     float n_bins_inc = 0.0;
        //     for (int xbin=1; xbin<=n_bins_x; xbin++)
        //     {
        //         for (int ybin=1; ybin<=n_bins_y; ybin++)
        //         {
        //             // get bin content
        //             int bin_id = roi->GetBin(xbin, ybin);
        //             float bin_content = roi->GetBinContent(bin_id);

        //             if (bin_content != 0.0){
        //                 n_bins_inc += 1;
        //             }
        //         }
        //     }

        //     mytot1 += n_bins_inc;
        //     mytot2 += n_bins_tot;
        // }
    }

    //printf("mytot1: %f \n", mytot1);
    //printf("mytot2: %f \n", mytot2);
    //printf("ROI bins included: %f \n", mytot1/mytot2);
}


