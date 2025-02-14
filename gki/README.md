# GKI Directory Tree

The path names here are intended to be concise and unambiguous.

```none
gki
|-- README.md
|-- aarch64
|   |-- defconfig
|   |   |-- allmodconfig
|   |   +-- ...
|   |-- symbols
|   |   |-- base
|   |   |-- virtual_device
|   |   |-- $partner
|   |   +-- ...
|   |-- protected_exports
|   |-- abi.stg
|   +-- abi.stg.allowed_breaks
+-- ...
```

The `gki` directory has one subdirectory per
[Kleaf](https://android.googlesource.com/kernel/build/+/refs/heads/main/kleaf/README.md)
architecture. Within each such subdirectory:

* `defconfig` - contains fragments for Kleaf builds
   * `allmodconfig` - post-defconfig allmodconfig fragment
* `symbols` - contains symbol list files
   * `base` - a short list of symbols that are essential for ABI safety
   * `$partner` - a symbol list file for a specific partner
      * maintained by the partner
      * e.g. `kmi_symbol_list = "//common:gki/aarch64/symbols/acme"`
      * e.g. `tools/bazel run //modules:acme_aarch64_abi_update_symbol_list`
* `protected_exports` - a list of symbols owned by GKI modules
   * maintained by Kleaf
   * e.g. `tools/bazel run //common:kernel_aarch64_abi_update_protected_exports`
* `abi.stg` - the tracked ABI
   * maintained by Kleaf
   * e.g. `tools/bazel run //common:kernel_aarch64_abi_update`
* `abi.stg.allowed_breaks` - a list of allowed ABI differences
   * for use by Gerrit ABI monitoring
