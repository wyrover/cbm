#ifndef CBM_PORE_SIZE_H
#define CBM_PORE_SIZE_H

#include "common.h"
#include <row.h>

namespace cbm {

class PoreSize
{
public:
	PoreSize();
	PoreSize(long id);
	PoreSize(soci::row& rs);
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	double getSizeQ() const;
	void setSizeQ(const double& value);
	double getSizeV() const;
	void setSizeV(const double& value);
	double getSizeD() const;
	void setSizeD(const double& value);
	double getSizeP() const;
	void setSizeP(const double& value);
	double getSizeSigma() const;
	void setSizeSigma(const double& value);
	double getSizeDelta() const;
	void setSizeDelta(const double& value);

private:
	long pore_size_id;
	double size_q;
	double size_v;
	double size_d;
	double size_p;
	double size_sigma;
	double size_delta;

}; // class PoreSize

} // namespace cbm

#endif // CBM_PORE_SIZE_H
