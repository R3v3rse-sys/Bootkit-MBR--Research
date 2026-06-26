# 🛡️ Bootkit Research (MBR/UEFI) 

> **⚠️ WARNING: FOR EDUCATIONAL & DEFENSIVE RESEARCH ONLY**  
> *This is a Proof of Concept (PoC) for understanding low-level Windows security.  
> **NEVER RUN ON REAL HARDWARE.** Only use in isolated Virtual Machines (VM).*  
> *I am NOT responsible for any damage or misuse.*

---

## 🎯 What is this Project?

This repository demonstrates a **Bootkit** - a sophisticated piece of code that runs **before the Operating System boots**. 

It's designed to show:

- ✅ **Anti-VM & Anti-Debugger** techniques (bypassing analysis environments).
- ✅ **Deep Persistence** by modifying the **Master Boot Record (MBR)**.
- ✅ **Payload Execution** after Windows loads (changing desktop wallpaper as a harmless demo).
- ✅ **Stealth Mechanisms** (hooking disk interrupts to hide itself).

**This is NOT malware.** It's an educational toolkit for **Red Teamers, Defenders, and Security Researchers** to understand and defend against real-world Bootkits.

---

## 🚀 Why I Built This

I'm a Reverse Engineer and Exploit Developer (16-20 age range) passionate about low-level systems and cybersecurity. 

This project is part of my journey to build an **international red-team squad**. It showcases my skills in:

- **Assembly & C** programming.
- **Windows Internals** (MBR, Kernel, Registry).
- **Offensive Security** research.
- **Creative problem-solving**.

---

## 📂 Project Structure

```bash
📁 Bootkit-Research/
├── 📄 README.md                # You are here!
├── 📄 LICENSE                  # MIT License (Open Source)
├── 📁 mbr/
│   ├── bootkit.asm             # Core MBR Bootkit (Assembly)
│   ├── installer.c             # Windows installer (C)
│   ├── payload.c               # Post-boot payload (Wallpaper changer)
│   └── Makefile                # Build automation
├── 📁 uefi/
│   └── bootkit.c               # UEFI version (conceptual)
├── 📁 docs/
│   ├── architecture.md         # How it works
│   └── defense-strategies.md   # How to defend against Bootkits
└── 📁 tools/
    ├── backup_mbr.c            # Backup original MBR
    └── restore_mbr.c           # Restore original MBR
```

---

## 🧠 How It Works (Step-by-Step)

### Phase 1: Boot Sector Infection
- The Assembly code (`bootkit.asm`) is written to **Sector 0** (MBR) of the disk.
- It checks for Virtual Machines or Debuggers to avoid analysis.
- If safe, it loads the hidden payload from a secret sector.

### Phase 2: Stealth Hook
- It hooks **INT 13h** (disk interrupt).
- When Windows tries to read the MBR, it serves the **clean backup** instead of the infected one.
- 👻 The Bootkit becomes **invisible** to AV and system tools!

### Phase 3: Windows Payload
- After Windows boots, the `payload.exe` runs automatically.
- It waits for the desktop to load, then changes the wallpaper to:

> **"You Are Hacked :)"**

- It also installs a **Registry Run Key** to survive reboots.

---

## ⚙️ How to Build & Test (VM ONLY)

### Prerequisites
- **Linux (WSL or Native)** or **Windows with MinGW**.
- **NASM** (Assembler) and **GCC** (Compiler).

### Build Commands

```bash
# 1. Clone the repo
git clone https://github.com/your-username/Bootkit-Research.git
cd Bootkit-Research/mbr

# 2. Install dependencies (Debian/Ubuntu)
sudo apt install nasm gcc mingw-w64

# 3. Compile everything
make all

# 4. Transfer to Windows VM
# Copy bootkit.bin, installer.exe, and payload.exe to your VM.
```

### Install (in Windows VM as Administrator)

```bash
# Run the installer
installer.exe

# Follow the on-screen prompts.
# Reboot the VM to see the effect!
```

---

## 🛡️ How to Uninstall

```bash
# Run the installer again and choose 'Uninstall'
# OR restore the MBR backup manually.
```

---

## 📜 License

This project is licensed under the **MIT License** – feel free to use, modify, and share **for educational purposes**.

---

## 🤝 Join the Team!

I'm actively looking for **3 passionate people (ages 16-20)** to build a **small, international cybersecurity team**.

**Roles we need:**
- 🕵️‍♀️ **Web Penetration Tester** (OWASP, APIs, logic bugs)
- 💼 **Project Manager / Sales** (contracts, client comms, budget)
- 🌐 **Network & Infrastructure Specialist** (scanning, firewalls, DNS)

**Our Mission:**
- 🌍 International pentesting projects.
- 💶 Dollar-based income.
- 🎉 Casual, friendly, no corporate nonsense.
- 🚀 Professional growth and learning.

**If you're hungry, motivated, and want to build something awesome – DM me on Discord or open an Issue here!**

---

## ⭐ Star this repo if you found it useful!

---

## 🏆 Acknowledgments

- [MBR Documentation](https://wiki.osdev.org/MBR)
- [Windows Internals](https://learn.microsoft.com/en-us/sysinternals/)
- [Hack The Box](https://www.hackthebox.com/) – for the inspiration.
- All the amazing security researchers out there!

---

**Built with ❤️ by a 18-year-old Reverse Engineer from Iran.**  
*"The best way to predict the future is to create it."*
