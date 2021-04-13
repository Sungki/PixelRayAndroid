set(
	commun_sources
	${PIXELRAY_SRC_DIR}/main.cpp
)

set(
	pixelray
	${commun_sources}
	${PIXELRAY_SRC_DIR}/SDL_android_main.c
)