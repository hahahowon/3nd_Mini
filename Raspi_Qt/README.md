Raspberry Pi QR Button Client
라즈베리파이 카메라로 QR 코드를 실시간 추적하고, 버튼이 눌렸을 때 1초 동안 디코딩된 첫 QR 코드를 TCP 서버로 전송하는 프로그램입니다.

1. 시스템 사양 확인
bash
uname -a
cat /etc/os-release
lscpu
사용 예시: Raspberry Pi 4, Raspberry Pi OS (64-bit), ARM Cortex-A72

2. 의존 패키지 설치
bash
sudo apt update
sudo apt install -y \
  cmake git build-essential \
  libgtk2.0-dev pkg-config \
  libavcodec-dev libavformat-dev libswscale-dev


3. 기존 OpenCV 제거 (선택)
bash
sudo apt remove -y libopencv-dev
이전에 설치한 OpenCV 패키지와 충돌 방지를 위해 제거 권장

4. OpenCV + Contrib 소스 코드 다운로드

bash
cd ~
rm -rf opencv opencv_contrib  # 이전 소스 제거
git clone --depth=1 https://github.com/opencv/opencv.git
git clone --depth=1 https://github.com/opencv/opencv_contrib.git


5. OpenCV 빌드 & 설치
bash
cd ~/opencv
mkdir -p build && cd build

cmake .. \
  -DOPENCV_EXTRA_MODULES_PATH=~/opencv_contrib/modules \
  -DWITH_QUIRC=ON \
  -DWITH_QT=OFF \
  -DBUILD_opencv_python=OFF \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX=/usr/local

make -j$(nproc)
sudo make install
sudo ldconfig

QUIRC는 OpenCV에서 QR 인식을 위한 디코더입니다.

6. WiringPi 설치 (버튼 제어)
bash
if ! command -v gpio &> /dev/null; then
    git clone https://github.com/WiringPi/WiringPi.git
    cd WiringPi
    ./build
fi

7. 코드 컴파일
CMakeLists.txt
cmake
cmake_minimum_required(VERSION 3.10)
project(QR_Button_Client)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(qr_client main.cpp)
target_link_libraries(qr_client ${OpenCV_LIBS} wiringPi)


빌드 명령어

bash
mkdir -p build && cd build    # 경로는 QR_Scen_Client/ mkdir은 처음에만
cmake ..
make



디렉토리 구조

QR_Scen_Client/                # 프로젝트 파일
├── CMakeLists.txt
├── README.md
├── install_opencv.sh            # OpenCV + WiringPi 설치 스크립트
├── src/
│   └── main.cpp                 # QR 인식 및 TCP 전송 메인 소스코드
├── build/                       # mkdir build로 만든 CMake 빌드 디렉토리