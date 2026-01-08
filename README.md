# Liquid QR Coder v1.0

![Banner](resources/banner.png)

> **"누구나 쉽고 간편하게, 스타일리시한 QR 코드를 생성하세요."**

Liquid QR Coder는 현대적인 **Liquid Glassmorphism** 디자인이 적용된 강력한 C++ 기반 QR 코드 생성기입니다. 텍스트를 입력하는 즉시 아름다운 인터페이스 상에 QR 코드가 실시간으로 나타납니다.

## 🌟 주요 기능

- **실시간 생성**: 입력과 동시에 QR 코드가 즉각적으로 업데이트됩니다.
- **프리미엄 디자인**: 60FPS 애니메이션 액체 배경과 유리 질감의 UI 요소.
- **커스텀 타이틀바**: 시스템 기본 창 대신 앱 테마와 어우러지는 독자적인 타이틀바 제공.
- **다국어 지원**: 한국어와 영어를 자유롭게 전환할 수 있습니다.
- **고해상도 출력**: 스캔이 용이한 깨끗한 품질의 QR 코드를 생성합니다.

## 🚀 시작하기

### 실행 방법
별도의 설치 없이 빌드된 바이너리를 실행하여 바로 사용할 수 있습니다.
```bash
./build/appLiquidQR
```

### 빌드 방법
프로젝트를 직접 빌드하려면 Qt 6 개발 환경과 CMake가 필요합니다.
```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

## 🛠 기술 스택
- **Language**: C++17
- **Framework**: Qt 6.4+ (QtWidgets)
- **Library**: Nayuki QR Code Generator (Embedded)
- **Build System**: CMake

## 📝 라이선스
이 프로젝트는 **MIT 라이선스**에 따라 배포됩니다. 자세한 내용은 [LICENSE](LICENSE) 파일을 참조하세요.

## 👤 제작자
- **Rheehose (Rhee Creative)**
- Copyright (c) 2008-2026 Rheehose (Rhee Creative)

---

*본 버전(v1.0)은 2026년 1월 8일 (KST)에 최종 업데이트되었습니다.*
