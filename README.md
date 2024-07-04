
# Manual Linux Build

The Manual Linux Build project is a comprehensive guide to building a barebones kernel and root filesystem using the ARM cross-compile toolchain. This project includes scripts to automate the build process and boot the system using QEMU, as well as testing scripts to validate the implementation.

## Installation Instructions

1. Clone the repository to your local machine using:

```bash
  git clone https://github.com/AbhinitShetty/CustomLinuxKernelBuild.git
```
2. Navigate to the project directory:

```bash
  cd finder-app/
```
3. Make the shell scripts executable:
```bash
  chmod +x manual-linux.sh start-qemu-terminal.sh finder-test.sh full-test.sh
  ```

4. Ensure you have the ARM cross-compile toolchain and QEMU installed on your system.

## Project Explanation

This project includes a BASH script `finder-app/manual-linux.sh` that uses the ARM cross-compile toolchain to build a barebones kernel and root filesystem, and boots using QEMU.

1. **manual-linux.sh** 
The `manual-linux.sh` script is designed to:
- Completely build or rebuild all components in a new or existing directory `outdir` with the installed kernel.
- Build Kernel Image
- Build Root Filesystem
- Cross Compile writer application `writer.out`
- Create Standalone Initramfs
- Operate non-interactively, requiring only the `outdir` command line argument when run the first time on a new `outdir`.
- Usage:
```bash
  ./manual-linux.sh <outdir>
```

2. **start-qemu-terminal.sh**
This script starts a QEMU instance using the build directory.
- Usage:
```bash
  ./start-qemu-terminal.sh
```
After booting, you can log in with no username and password, and then run `./finder-test.sh` from the QEMU console prompt to get a success response. The writer application should run successfully inside QEMU after being cross-compiled.

3. **finder-test.sh** 
This script runs tests to ensure the writer application runs successfully inside the QEMU instance.
- Usage:
```bash
  ./finder-test.sh
```

4. **full-test.sh**
The `full-test.sh` script validates the entire implementation, including:
- The content of systemcalls.c unit tests.
- The `manual-linux.sh` script.
- The QEMU operation.
- Usage:
```bash
  ./full-test.sh
```
Run this script to ensure all functionalities are working as expected.

## Current Status
The kernel image has been successfully built and the QEMU instance boots up as expected. The ARM cross-compiled `writer.out` file functions correctly, and this can be verified by running the `finder-test.sh` script within the QEMU instance. However, a few checks in the `full-test.sh` script are still pending validation. As a result, the GitHub Actions self-hosted runner currently indicates incomplete success. These issues will be resolved shortly.

## Summary 
This project automates the process of building and booting a barebones Linux kernel and root filesystem using ARM cross-compilation and QEMU, providing scripts to build, test, and validate the implementation efficiently.
