#include "view/context/context.hpp"
#include "mainwindow.hpp"

View::Context::Context::Context(lib::spt::api &spotify, const lib::settings &settings,
	spt::Current &current, const lib::cache &cache, QWidget *parent)
	: QDockWidget(parent)
{
	content = new View::Context::Content(spotify, current, cache, this);
	setWidget(content);

	title = new View::Context::Title(spotify, settings, current, cache, this);
	setTitleBarWidget(title);

	setFeatures(QDockWidget::NoDockWidgetFeatures);
}

void View::Context::Context::updateContextIcon()
{
	if (title != nullptr)
	{
		title->updateIcon();
	}
}

void View::Context::Context::resetCurrentlyPlaying()
{
	if (content != nullptr)
	{
		content->reset();
	}
}

auto View::Context::Context::getCurrentlyPlaying() const -> const lib::spt::track &
{
	if (content == nullptr)
	{
		throw std::runtime_error("No content");
	}
	return content->getCurrentlyPlaying();
}

void View::Context::Context::setCurrentlyPlaying(const lib::spt::track &track)
{
	if (content != nullptr)
	{
		content->setCurrentlyPlaying(track);
	}
}

void View::Context::Context::setAlbum(const QPixmap &pixmap)
{
	if (content != nullptr)
	{
		content->setAlbum(pixmap);
	}
}