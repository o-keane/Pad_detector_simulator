# Pad_detector_simulator
A program to simulate a pad detector and plot fields and drift paths of electrons and holes in KDetSim.

 The program uses the KDetSim library in root, Cern's open-source data analysis framework. KDetSim may be installed from here: http://kdetsim.org/ and root from here: https://root.cern/install/. Root takes C++ arguments.
 
 PadDetector.C simulates a didoe with an electrode for two of its sides. PadDetector2.C is slightly more sophisticated, modelling the heavily n-doped region embedded into one side of the diode without spreading right ot the edges.
 
 ELectrons and holes are generated within the diode and their drift paths plotted.
 
 The electric field and electric potential across the didoe are plotted in 2D, as well as the weighting field and weighting potential.
 
 The current diode dimensions are those of the ATLAS-18 MD8 pad diode. See examples below:
 
 <img width="757" alt="Screenshot 2021-03-16 at 15 22 42" src="https://user-images.githubusercontent.com/81777782/113507174-cb870080-9540-11eb-9ff6-7c0266e7acfe.png">
<img width="754" alt="Screenshot 2021-03-16 at 17 10 03" src="https://user-images.githubusercontent.com/81777782/113507195-f1140a00-9540-11eb-9e13-808cd3ea91f6.png">

