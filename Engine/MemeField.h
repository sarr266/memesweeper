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
		void Reveal();
		bool isRevealed() const;
		void ToggleFlag();
		bool isFlagged() const;
		void SetNeighborMemeCount(int memeCount);
	private:
		State state = State::Hidden;
		bool hasMeme = false;
		int nNeighborMemes = -1; //-1 indicates that the variable has not been assigned any value
	};
public:
	MemeField(int nMemes);
	void Draw(Graphics& gfx) const; //to Draw rhe grid (grid consists of tiles so we'll have to call Tile::Draw)
	RectI GetRect() const;
	void OnRevealClick(const Vei2& screenPos);
	void OnFlagClick(const Vei2& screenPos);
	int CountNeighborMemes(const Vei2& gridPos);
private:
	Tile& TileAt(const Vei2& gridPos); //position in tiles, called in non-const context
	const Tile& TileAt(const Vei2& gridPos) const; //for const tilemaps, called in const context
	Vei2 ScreenToGrid(const Vei2& screenPos);
private:
	static constexpr int width = 20;
	static constexpr int height = 16;
	Tile field[width * height];
};