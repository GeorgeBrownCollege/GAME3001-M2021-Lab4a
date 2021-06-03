#pragma once
#ifndef __TILE__
#define __TILE__

#include "Label.h"
#include "NavigationObject.h"
#include "NeighbourTile.h"
#include "TileStatus.h"

class Tile : public NavigationObject
{
public:
	Tile();
	~Tile();
	
	void draw() override;
	void update() override;
	void clean() override;

	// Getters and Setters
	Tile* getNeighbourTile(NeighbourTile position);
	float getTileCost() const;
	TileStatus getTileStatus() const;
	
	void setNeighbourTile(NeighbourTile position, Tile* tile);
	void setTileCost(float cost);
	void setTileStatus(TileStatus status);

	// utility functions
	void addLabels();
	void setLabelsEnabled(bool state);

private:
	float m_cost;
	TileStatus m_status;

	Label* m_costLabel;
	Label* m_statusLabel;
	
	Tile* m_neighbours[NUM_OF_NEIGHBOUR_TILES];
};

#endif /* defined (__TILE__) */