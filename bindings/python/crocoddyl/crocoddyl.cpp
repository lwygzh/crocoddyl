///////////////////////////////////////////////////////////////////////////////
// BSD 3-Clause License
//
// Copyright (C) 2018-2019, LAAS-CNRS
// Copyright note valid unless otherwise stated in individual files.
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#include <boost/python.hpp>
#include <eigenpy/eigenpy.hpp>

#include "python/crocoddyl/core.hpp"
#include "crocoddyl/core/utils/version.hpp"

namespace crocoddyl {
namespace python {

namespace bp = boost::python;

BOOST_PYTHON_MODULE(libcrocoddyl_pywrap) {
  bp::scope().attr("__version__") = printVersion();

  eigenpy::enableEigenPy();

  typedef double Scalar;
  typedef Eigen::Matrix<Scalar, Eigen::Dynamic, 1> VectorX;
  typedef Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> MatrixX;
  eigenpy::enableEigenPySpecific<VectorX>();
  eigenpy::enableEigenPySpecific<MatrixX>();

  exposeCore();
}

}  // namespace python
}  // namespace crocoddyl
