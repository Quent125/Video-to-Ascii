#include <opencv2/opencv.hpp>

#include <chrono>
#include <iostream>
#include <thread>
using namespace std;
using namespace cv;

string pixelToASCII(int pixel_intensity) // 接受像素的亮度值
{
  // const string ASCII_CHARS = "@$%#&!*+=-_.                ";
  // const string ASCII_CHARS = "@#&!*+=-_.     ";
  const string ASCII_CHARS = "   ._-=+*!&#%$@"; // 亮度由低到高
  string s =
      string(1, ASCII_CHARS[pixel_intensity * ASCII_CHARS.length() / 256]); // 初始化為長度為1的字串。256代表像素亮度值的範圍，將像素的亮度值映射到 0 到 ASCII_CHARS.length()-1 的範圍，以便根據亮度值選擇適當的 ASCII 字符。
  return s;
}

int main()
{

  /*int ScreenW, ScreenH, VideoW, VideoH;
  printf("Please Enter Your Screen Resolution\n");
  printf("Enter Width:\n");
  scanf("%d", &ScreenW);
  printf("Enter Height:\n");
  scanf("%d", &ScreenH);
  printf("Please Enter Your Video Resolution\n");
  printf("Enter Width:\n");
  scanf("%d", &VideoW);
  printf("Enter Height:\n");
  scanf("%d", &VideoH); */

  // double x = ((double)ScreenH * (double)VideoH) / ((double)ScreenW * (double)VideoW);

  // string video_path = "D:\\Code\\Video-to-Ascii\\vid2.mp4"; // For Desktop
  string video_path = "C:\\Code\\Video-to-Ascii\\vid3.mp4"; // For Laptop
  VideoCapture cap(video_path);

  double fps = cap.get(CAP_PROP_FPS);

  cout << fps << endl;

  int frame_duration_ms = 1000 / fps;

  int width = 140;

  int height = 50;

  int frame_width = cap.get(CAP_PROP_FRAME_WIDTH);
  int frame_height = cap.get(CAP_PROP_FRAME_HEIGHT);
  cout << frame_width << " " << frame_height << endl;

  height = (width * frame_height / frame_width) * 0.3627; // Laptop

  // height = (width * frame_height / frame_width) * 0.4318; // Desktop

  /* Laptop : 251*389 Pscreen  1366*768 Screen    ((251/1366)*768)/389 = 0.3627

   Desktop : 750*977 Pscreen    2560*1440 Screen  ((750/2560)*1440)/977 = 0.4318 */

  Mat frame, gray_frame, resized_frame;

  while (true)
  {
    cap >> frame;
    if (frame.empty())
      break;

    cv::cvtColor(frame, gray_frame, cv::COLOR_BGR2GRAY);

    resize(gray_frame, resized_frame, Size(width, height), 0, 0, INTER_LINEAR);

    string ascii_frame;
    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
        ascii_frame += pixelToASCII(resized_frame.at<uchar>(i, j));
      }
      ascii_frame += "\n";
    }

    system("cls"); // to clear the console
    cout << ascii_frame;
    std::this_thread::sleep_for(std::chrono::milliseconds(frame_duration_ms )); // 影格暫停,From Chrono
  }
  return 0;
}