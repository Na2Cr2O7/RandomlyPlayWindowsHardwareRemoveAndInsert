## 🎵 RandomlyPlayWindowsHardwareRemoveAndInsert

### English Version

Randomly plays the Windows system sounds *Hardware Remove* and *Hardware Insert*, along with the generic notification sound *Windows Notify System Generic.wav*. It simulates the occasional unplugging and plugging of USB devices.

### Requirements

- **Build Environment**: Visual Studio 2022 is recommended.
- Alternatively, you can use MinGW:

```bash
g++ RandomlyPlayWindowsHardwareRemoveAndInsert.cpp -o RandomlyPlayWindowsHardwareRemoveAndInsert.exe -l winmm
```

> Note: The `-l winmm` flag links to the Windows Multimedia library, which is required for playing system sounds.

### ⚠️ Warning

Make sure this program is running in the foreground when you start it. Otherwise, I won't sure which window will be hidden.

---

### 中文版本

随机播放 Windows 系统音效中的 *硬件移除* 和 *硬件插入* 声音，并伴随通用通知音 *Windows Notify System Generic.wav*，就像你的 USB 设备偶尔被拔出又插入一样。

### 所需环境

- 推荐使用 **Visual Studio 2022** 编译。
- 也可以尝试使用 MinGW 编译：

```bash
g++ RandomlyPlayWindowsHardwareRemoveAndInsert.cpp -o RandomlyPlayWindowsHardwareRemoveAndInsert.exe -l winmm
```

> 注意：`-l winmm` 参数用于链接 Windows 多媒体库，这是播放系统声音所必需的。

### ⚠️ 警告

请确保程序启动时处于前台运行状态，否则我也不知道哪个窗口被隐藏了。

