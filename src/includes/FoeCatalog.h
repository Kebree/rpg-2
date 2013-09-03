/*
 * FoeCatalog.h
 *
 *  Created on: 30 août 2013
 *      Author: jgintrand
 */

#ifndef FOECATALOG_H_
#define FOECATALOG_H_

#include <Foe.h>
#include <vector>


class FoeCatalog {
public:
	FoeCatalog();
	virtual ~FoeCatalog();
	Foe getTier1();
private:
	std::vector<Foe> tier1;
};

#endif /* FOECATALOG_H_ */
