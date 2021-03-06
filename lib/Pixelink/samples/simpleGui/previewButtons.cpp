
/***************************************************************************
 *
 *     File: previewButtons.cpp
 *
 *     Description: controls the (preview) play/pause/stop buttons for a simple
 *                  camera application
 */

#include "simpleGui.h"

// Prototypes
extern GtkWindow *topLevelWindow;


PxLPreviewButtons::PxLPreviewButtons (GtkWidget *play, GtkWidget *pause, GtkWidget *stop)
: m_play(play)
, m_pause(pause)
, m_stop(stop)
{
}

PxLPreviewButtons::~PxLPreviewButtons ()
{
}

void PxLPreviewButtons:: greyAll()
{
	gtk_widget_set_sensitive (m_play, false);
	gtk_widget_set_sensitive (m_pause, false);
	gtk_widget_set_sensitive (m_stop, false);
}

void PxLPreviewButtons:: activatePlay()
{
	gtk_widget_set_sensitive (m_play, true);
}
void PxLPreviewButtons:: activatePause()
{
	gtk_widget_set_sensitive (m_pause, true);
}
void PxLPreviewButtons:: activateStop()
{
	gtk_widget_set_sensitive (m_stop, true);
}

extern "C" void PlayButtonPressed
    (GtkWidget* widget, GdkEventExpose* event, gpointer userdata )
{

	gtk_widget_set_sensitive (previewObject->m_play, false);
	gtk_widget_set_sensitive (previewObject->m_pause, true);
	gtk_widget_set_sensitive (previewObject->m_stop, true);

	if (pCamera) pCamera->play();

    // The above 'play' operation may have opened the preview on top of our
	// application.  How rude!!
	// Reassert our application on top.
	gtk_window_set_keep_above( topLevelWindow, true );

}

extern "C" void PauseButtonPressed
    (GtkWidget* widget, GdkEventExpose* event, gpointer userdata )
{

	gtk_widget_set_sensitive (previewObject->m_play, true);
	gtk_widget_set_sensitive (previewObject->m_pause, false);
	gtk_widget_set_sensitive (previewObject->m_stop, true);

	if (pCamera) pCamera->pause();
}

extern "C" void StopButtonPressed
    (GtkWidget* widget, GdkEventExpose* event, gpointer userdata )
{

	gtk_widget_set_sensitive (previewObject->m_play, true);
	gtk_widget_set_sensitive (previewObject->m_pause, false);
	gtk_widget_set_sensitive (previewObject->m_stop, false);

	if (pCamera) pCamera->stop();

	// We don't need to worry about the preview window anymore, so no need to
	// keep our application on top of it.
	gtk_window_set_keep_above( topLevelWindow, false );
}


