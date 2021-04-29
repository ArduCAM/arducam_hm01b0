if (NOT TARGET arducam_hm01b0)
    add_library(arducam_hm01b0 INTERFACE)

    pico_generate_pio_header(arducam_hm01b0
      ${CMAKE_CURRENT_LIST_DIR}/image.pio)

    target_sources(arducam_hm01b0 INTERFACE
      ${CMAKE_CURRENT_LIST_DIR}/arducam_hm01b0.c)

    target_link_libraries(arducam_hm01b0 INTERFACE pico_stdlib hardware_i2c hardware_pio hardware_dma)
endif()
   