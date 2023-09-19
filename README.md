# Video-to-Ascii
將影片轉為ascii呈現

安裝msys64之後，在mingw64中安裝opencv

縮放比:(height*frame_width)/(width*frame_height)

Compile: 
 g++ -g main.cpp -I C:\msys64\mingw64\include -lopencv_core455 -lopencv_imgcodecs455 -lopencv_imgproc455 -lopencv_calib3d455 -lopencv_dnn455 -lopencv_features2d455 -lopencv_flann455 -lopencv_gapi455 -lopencv_highgui455 -lopencv_ml455 -lopencv_objdetect455 -lopencv_photo455 -lopencv_stitching455 -lopencv_video455 -lopencv_videoio455 -o main.exe


