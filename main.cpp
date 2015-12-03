#include <iostream>
#include <cv.h>
#include <opencv2/core/core.hpp> 
#include <highgui.h>

const char *filename = "test.jpg";

//--- プロトタイプ宣言 ---//
void Mouse( int event, int x, int y, int flags ,void *param);


//---------- メイン関数 -----------//
int main( int argc, char **argv)
{
    cv::VideoCapture cap(0); // デフォルトカメラをオープン
    if(!cap.isOpened())  // 成功したかどうかをチェック
        return -1;

    cv::Mat input_image;
    cv::namedWindow("window1",1);
    cvSetMouseCallback("window1",Mouse);
	
    for(;;)
    {
        cv::Mat frame;
        cap >> frame; // カメラから新しいフレームを取得
        input_image=frame;      //matのコピーは普通に=で結べば良いみたい．
        imshow("window1", input_image);
        if(cv::waitKey(30) >= 0) break;
    }
    // VideoCapture デストラクタにより，カメラは自動的に終了処理されます
    return 0;
}


//--------- ここからコールバック関数 -----------//
void Mouse( int event, int x, int y, int flags ,void *param = NULL) // コールバック関数
{
        switch(event)
        {
                case CV_EVENT_LBUTTONDOWN:
                        std::cout << x << "," << y << "\n";
                break;

                default:
                break;
        }

}
