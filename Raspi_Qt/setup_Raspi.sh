#!/bin/bash

set -e  # Exit immediately if a command exits with a non-zero status
LOG="opencv_qr_setup.log"
exec > >(tee -i $LOG) 2>&1

echo "[1/7] Checking system information..."
uname -a
cat /etc/os-release
lscpu

echo "[2/7] Installing required packages..."
sudo apt update
sudo apt install -y cmake git build-essential libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev

echo "[3/7] Removing existing OpenCV installation (if any)..."
sudo apt remove -y libopencv-dev || true

echo "[4/7] Cloning OpenCV and OpenCV-contrib source..."
cd ~
rm -rf opencv opencv_contrib
git clone --depth=1 https://github.com/opencv/opencv.git
git clone --depth=1 https://github.com/opencv/opencv_contrib.git

echo "[5/7] Preparing OpenCV build..."
cd ~/opencv
mkdir -p build && cd build

cmake .. \
  -DOPENCV_EXTRA_MODULES_PATH=~/opencv_contrib/modules \
  -DWITH_QUIRC=ON \
  -DWITH_QT=OFF \
  -DBUILD_opencv_python=OFF \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX=/usr/local

echo "[6/7] Building OpenCV... (this may take a while)"
make -j$(nproc)

echo "[7/7] Installing OpenCV..."
sudo make install
sudo ldconfig

echo "OpenCV installation complete."

echo "Checking if WiringPi is installed..."
if ! command -v gpio &> /dev/null; then
    echo "🔧 Installing WiringPi..."
    git clone https://github.com/WiringPi/WiringPi.git
    cd WiringPi
    ./build
    echo "WiringPi installation complete."
else
    echo "WiringPi is already installed."
fi

echo "All setup steps completed successfully!"
