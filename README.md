# protodune-roi-analysis

Root and python scripts to analyze ROI efficiency on protodune data

Procedure:

1. Run wct on raw data without ROI to get orig root file   
2. Run wct on raw data with ROI
3. Modify roi_data_parser.C and roi_bin_inclusion.C with filename of wct root output file   
4. Run roi_data_parser.C and roi_bin_inclusion.C   
5. Run relevant parts of Track Detection.ipynb to get efficiency

