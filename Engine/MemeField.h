#pragma once
#include "Vei2.h"
#include "Graphics.h"

class MemeField
{
private:
	class Tile
	{
	public:
		enum class State
		{
			Hidden,
			Flagged,
			Revealed
		};
	public:
		void SpawnMeme();
		bool HasMeme() const;
		void Draw(const Vei2& screenPos, Graphics& gfx) const; //position on screen in pixels, to draw Tiles
	private:
		State state = State::Hidden;
		bool hasMeme = false;
	};
public:
	MemeField(int nMemes);
	void Draw(Graphics& gfx) const; //to Draw rhe grid (grid consists of tiles so we'll have to call Tile::Draw)
private:
	Tile& TileAt(const Vei2& gridPos); //position in tiles, called in non-const context
	const Tile& TileAt(const Vei2& gridPos) const; //for const tilemaps, called in const context
private:
	static constexpr int width = 20;
	static constexpr int height = 16;
	Tile field[width * height];
};