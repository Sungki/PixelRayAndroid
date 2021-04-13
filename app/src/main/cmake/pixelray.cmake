set(
	commun_sources
		${PIXELRAY_SRC_DIR}/main.cpp
		${PIXELRAY_SRC_DIR}/Game.cpp
		${PIXELRAY_SRC_DIR}/Flock.cpp
		${PIXELRAY_SRC_DIR}/Boid.cpp
		${PIXELRAY_SRC_DIR}/Vector2D.cpp
		${PIXELRAY_SRC_DIR}/TextureLoader.cpp
)

set(
	pixelray
	${commun_sources}
	${PIXELRAY_SRC_DIR}/SDL_android_main.c
)