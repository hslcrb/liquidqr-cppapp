# Liquid QR Coder v1.0

![Banner](resources/banner.png)

> **"Generate stylish QR codes easily and intuitively for anyone." / "누구나 쉽고 간편하게, 스타일리시한 QR 코드를 생성하세요."**

Liquid QR Coder is a powerful C++ based QR code generator featuring a modern **Liquid Glassmorphism** design. QR codes appear in real-time on a beautiful interface as you type.

This project was created through a collaboration between **Rheehose (Rhee Creative)** and **Google DeepMind's Gemini 2.0 Flash (Antigravity)**.

---

## 🌟 Key Features / 주요 기능

- **Real-time Generation / 실시간 생성**: QR codes update instantly as you type. / 입력과 동시에 QR 코드가 즉각적으로 업데이트됩니다.
- **Premium Design / 프리미엄 디자인**: 60FPS animated liquid background and glassmorphism UI. / 60FPS 애니메이션 액체 배경과 유리 질감의 UI 요소.
- **Custom Title Bar / 커스텀 타이틀바**: Unique title bar matching the app theme. / 앱 테마와 어우러지는 독자적인 타이틀바 제공.
- **Bilingual Support / 다국어 지원**: Switch freely between English and Korean. / 한국어와 영어를 자유롭게 전환할 수 있습니다.
- **High Quality / 고품질**: Clean QR codes for easy scanning. / 스캔이 용이한 깨끗한 품질의 QR 코드를 생성합니다.

---

## 🚀 Getting Started / 시작하기

This project supports **Windows, macOS, and Linux**. / 이 프로젝트는 **Windows, macOS, Linux** 환경을 모두 지원합니다.

### Instant Run/Build Scripts / 플랫폼별 즉시 실행 및 빌드 스크립트
Use the appropriate script for your platform. / 각 플랫폼에 맞는 스크립트를 사용하여 즉시 실행하거나 빌드할 수 있습니다.

- **Linux**: `./run_linux.sh`
- **Windows**: `run_windows.bat` (Requires CMake & Qt Environment / CMake 및 Qt 환경 필요)
- **macOS**: `./run_macos.sh` (Requires Qt6 via Homebrew / Homebrew를 통한 Qt6 필요)

### Detailed Build Instructions / 상세 빌드 방법
Qt 6 development environment and CMake are required on all platforms. / 모든 플랫폼에서 공통적으로 Qt 6 개발 환경과 CMake가 필요합니다.

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

---

## 📦 Installation (Linux) / 설치 (리눅스)

You can install the **.deb** package on Debian-based systems (Ubuntu, etc.). / 데비안 기반 시스템(우분투 등)에서는 **.deb** 패키지를 설치할 수 있습니다.

```bash
sudo dpkg -i liquidqr_1.0_amd64.deb
```

---

## 🛠 Technology Stack / 기술 스택
- **Language**: C++17
- **Framework**: Qt 6.4+ (QtWidgets)
- **Library**: Nayuki QR Code Generator
- **Build System**: CMake

## 📝 License / 라이선스
Distributed under the **MIT License**. / 이 프로젝트는 **MIT 라이선스**에 따라 배포됩니다. See [LICENSE](LICENSE) for details.

## 👤 Credits / 제작자
- **Rheehose (Rhee Creative)**
- **Gemini 2.0 Flash (Antigravity)**
- Copyright (c) 2008-2026 Rheehose (Rhee Creative)

---

*Last Updated: January 8, 2026 (KST)*
