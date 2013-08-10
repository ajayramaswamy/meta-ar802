OpenEmbedded BSP layer for Zealz GK802
======================================

This layer provides UNOFFICIAL support for Zealz GK802 platform for use
with OpenEmbedded and/or Yocto.



Dependencies
============

* URI: git://git.openembedded.org/openembedded-core
* branch: master
* revision: HEAD



Building the meta-gk802 layer
=============================

To build a BSP for the GK802, first set up your OE-core distribution,
then add to bblayers.conf the path to your local copy of meta-cubox.

Then, add to local.conf:

    MACHINE = "gk802"

For the rest, follow the building guidelines of the distro of your choice.



References
==========
https://community.freescale.com/docs/DOC-94849

https://github.com/dv1/meta-cubox

https://github.com/mtx512/linux-imx/tree/imx_3.0.35_4.0.0-gk802

https://github.com/imx6-dongle/uboot-imx6dongle/tree/for-upstream
