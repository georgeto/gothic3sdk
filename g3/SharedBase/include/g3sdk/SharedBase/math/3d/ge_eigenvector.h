#pragma once

#include <SharedBase/types/ge_def.h>
#include <SharedBase/types/ge_types.h>

class bCVector;

class GE_DLLIMPORT bCEigenVector
{
  public:
    static GEUInt error;

  public:
    explicit bCEigenVector(GEI32);
    ~bCEigenVector();

  public:
    bCEigenVector &operator=(bCEigenVector const &);

  public:
    void DecrSortEigenStuff();
    void DecrSortEigenStuff2();
    void DecrSortEigenStuff3();
    void DecrSortEigenStuff4();
    void DecrSortEigenStuffN();
    void EigenStuff();
    void EigenStuff2();
    void EigenStuff3();
    void EigenStuff4();
    void EigenStuffN();
    GEDouble Eigenvalue(GEI32);
    GEDouble const *Eigenvalue();
    GEDouble Eigenvector(GEI32, GEI32);
    GEDouble const **Eigenvector();
    void Eigenvector(GEI32, bCVector &) const;
    void IncrSortEigenStuff();
    void IncrSortEigenStuff2();
    void IncrSortEigenStuff3();
    void IncrSortEigenStuff4();
    void IncrSortEigenStuffN();
    GEDouble &Matrix(GEI32, GEI32);
    bCEigenVector &Matrix(GEDouble **);
    void Reduce();
    GEDouble &Tdiag(GEI32);
    GEDouble &Tsubdiag(GEI32);

  private:
    static GEUInt const allocation_failed;
    static GEUInt const invalid_size;
    static GELPCChar *message;
    static GEUInt const ql_exceeded;

  private:
    static GEI32 GE_STDCALL Number(GEUInt);
    static void GE_STDCALL Report(GEUInt);

  private:
    void DecreasingSort(GEI32, GEDouble *, GEDouble **);
    void IncreasingSort(GEI32, GEDouble *, GEDouble **);
    void QLAlgorithm(GEI32, GEDouble *, GEDouble *, GEDouble **);
    void Tridiagonal2(GEDouble **, GEDouble *, GEDouble *);
    void Tridiagonal3(GEDouble **, GEDouble *, GEDouble *);
    void Tridiagonal4(GEDouble **, GEDouble *, GEDouble *);
    void TridiagonalN(GEI32, GEDouble **, GEDouble *, GEDouble *);
};
