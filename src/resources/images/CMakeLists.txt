
INCLUDE(ebs/graphics)

ADD_IMAGE(IMAGE_SOURCES lena_96px_1bpp_c.bmp    "Monochrome" 1 ""     "")
ADD_IMAGE(IMAGE_SOURCES lena_96px_1bpp_a.jpg    "Monochrome" 1 "RLC"  "")
ADD_IMAGE(IMAGE_SOURCES q_vlogo_black_96px.jpg  "Monochrome" 1 "AUTO" "")
ADD_PLATFORM_LIBRARY(images STATIC "graphics" ${IMAGE_SOURCES})
