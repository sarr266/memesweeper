#pragma once
#include "Vei2.h"
#include "Graphics.h"

class MemeField
{
public:
	enum class State
	{
		Playing,
		Over,
		Winner
	};
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
		void Draw(const Vei2& screenPos, MemeField::State fieldState, Graphics& gfx) const; //position on screen in pixels, to draw Tiles
		void Reveal();
		bool isRevealed() const;
		void ToggleFlag();
		bool isFlagged() const;
		void SetNeighborMemeCount(int memeCount);
		bool HasNoNeighborMemes() const;
	private:
		State state = State::Hidden;
		bool hasMeme = false;
		int nNeighborMemes = -1; //-1 indicates that the variable has not been assigned any value
	};
public:
	MemeField(const Vei2& center, int nMemes);
	void Draw(Graphics& gfx) const; //to Draw rhe grid (grid consists of tiles so we'll have to call Tile::Draw)
	RectI GetRect() const;
	void OnRevealClick(const Vei2& screenPos);
	void OnFlagClick(const Vei2& screenPos);
	int CountNeighborMemes(const Vei2& gridPos);
	State GetState() const;
private:
	void RevealTile(const Vei2 gridPos);
	Tile& TileAt(const Vei2& gridPos); //position in tiles, called in non-const context
	const Tile& TileAt(const Vei2& gridPos) const; //for const tilemaps, called in const context
	Vei2 ScreenToGrid(const Vei2& screenPos);
	bool GameIsWon() const;
private:
	static constexpr int width = 10;
	static constexpr int height = 10;
	Vei2 topLeft;
	Tile field[width * height];
	static constexpr int borderThickness = 10;
	static constexpr Color borderColor = Colors::White;
	State state = State::Playing;
};