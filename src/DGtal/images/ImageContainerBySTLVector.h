/**
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 **/

#pragma once

/**
 * @file ImageContainerBySTLVector.h
 * @author David Coeurjolly (\c david.coeurjolly@liris.cnrs.fr )
 * Laboratoire d'InfoRmatique en Image et Systèmes d'information - LIRIS (CNRS, UMR 5205), CNRS, France
 *
 * @date 2010/06/15
 *
 * Header file for module ImageContainerBySTLVector.cpp
 *
 * This file is part of the DGtal library.
 */

#if defined(ImageContainerBySTLVector_RECURSES)
#error Recursive header files inclusion detected in ImageContainerBySTLVector.h
#else // defined(ImageContainerBySTLVector_RECURSES)
/** Prevents recursive inclusion of headers. */
#define ImageContainerBySTLVector_RECURSES

#if !defined ImageContainerBySTLVector_h
/** Prevents repeated inclusion of headers. */
#define ImageContainerBySTLVector_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include <vector>
#include "DGtal/base/Common.h"
#include "DGtal/images/CValue.h"
#include "DGtal/kernel/domains/CDomain.h"
#include "DGtal/kernel/NumberTraits.h"
//#include "DGtal/io/boards/Board2D.h"
#include "DGtal/io/Color.h"

//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{

  /////////////////////////////////////////////////////////////////////////////
  // class ImageContainerBySTLVector

  /**
   * Description of class 'ImageContainerBySTLVector' <p>
   *
   * Aim: Model of CImageContainer implementing the association Point<->Value
   * using a std::vector. A linearization of nD domain points
   * is used to build the std::vector index.
   *
   * The domain can be any model of CDomain (not necessarily an
   * HyperRectDomain instance).
   *
   * This class provides built-in iterators and fast SpanIterators
   * to perform 1D scans.
   *
   * @tparam TDomain a type for the image domain (model of CDomain).
   * @tparam TValue a type for image values (model of CValue).
   *
   * @see testImage.cpp
   * @see testImageContainerBenchmark.cpp
   */

  template <typename TDomain, typename TValue>
  class ImageContainerBySTLVector: public std::vector<TValue>
  {
  public:

    BOOST_CONCEPT_ASSERT(( CValue<TValue> ));
    BOOST_CONCEPT_ASSERT(( CDomain<TDomain> ));
      
    typedef TValue Value;
    typedef TDomain Domain;

    // static constants
    static const typename Domain::Dimension dimension = Domain::dimension;
    
    typedef typename Domain::Point Point;
    typedef typename Domain::Vector Vector;
    typedef typename Domain::Dimension Dimension;
    typedef typename Domain::Integer Integer;
    typedef typename Domain::Size Size;
    typedef typename vector<Value>::iterator Iterator;
    typedef typename vector<Value>::const_iterator ConstIterator;
    typedef typename vector<Value>::reverse_iterator ReverseIterator;
    typedef typename vector<Value>::const_reverse_iterator ConstReverseIterator;

    /** 
     * Constructor from a Domain
     * 
     * @param aDomain the image domain.
     * 
     */
    ImageContainerBySTLVector(const Domain &aDomain);

    /** 
     * Destructor.
     $
     */
    ~ImageContainerBySTLVector();

  
    /////////////////// Accessors //////////////////


    /**
     * Get the value of an image at a given position given
     * by a ConstIterator.
     *
     * @pre it must reference a point in the image domain.
     *
     * @param it  position in the image.
     * @return the value at aPoint.
     */
    Value operator()(ConstIterator &it) const
    {
      return (*it);
    };


    /**
     * Get the value of an image at a given position given
     * by a Iterator.
     *
     * @pre it must reference a point in the image domain.
     *
     * @param it  position in the image.
     * @return the value at aPoint.
     */
    Value operator()(Iterator &it) const
    {
      return (*it);
    };

    /**
     * Get the value of an image at a given position given
     * by a ConstIterator.
     *
     * @pre it must reference a point in the image domain.
     *
     * @param it  position in the image.
     * @return the value at aPoint.
     */
    Value operator()(ConstReverseIterator &it) const
    {
      return (*it);
    };


    /**
     * Get the value of an image at a given position given
     * by a Iterator.
     * 
     * @pre it must reference a point in the image domain.
     *
     * @param it  position in the image.
     * @return the value at aPoint.
     */
    Value operator()(ReverseIterator &it) const
    {
      return (*it);
    };



    /////////////////// Set values //////////////////

    /**
     * Set a value on an Image at a position specified by an Iterator.
     *
     * @pre @c it must reference a point in the image domain.
     *
     * @param it  iterator on the location.
     * @param aValue the value.
     */
    void setValue(Iterator &it, const Value &aValue)
    {
      (*it) = aValue;
    }  
    
    /**
     * Set a value on an Image at a position specified by a ReverseIterator.
     *
     * @pre @c it must reference a point in the image domain.
     *
     * @param it  a reverse iterator on the location.
     * @param aValue the value.
     */
    void setValue(ReverseIterator &it, const Value &aValue)
    {
      (*it) = aValue;
    }

   
     /////////////////// Interface //////////////////


    /**
     * Writes/Displays the object on an output stream.
     * @param out the output stream where the object is written.
     */
    void selfDisplay ( std::ostream & out ) const;


    /**
     * @return the validity of the Image
     */
    bool isValid() const
    {
      return (this != NULL);
    }


    /** 
     * Construct a ConstIterator on the image at a position specified
     * by @c aPoint
     * 
     * @param aPoint a point to construct a ConstIterator on. 
     * 
     * @return a ConstIterator on @c aPoint
     */
    ReverseIterator getReverseIterator(const Point &aPoint);
 
    /** 
     * Construct a Iterator on the image at a position specified
     * by @c aPoint
     * 
     * @param aPoint a point to construct a Iterator on. 
     * 
     * @return a Iterator on @c aPoint
     */
    ConstReverseIterator getconstReverseIterator(const Point &aPoint);
 
    /** 
     * Construct a ConstIterator on the image at a position specified
     * by @c aPoint
     * 
     * @param aPoint a point to construct a ConstIterator on. 
     * 
     * @return a ConstIterator on @c aPoint
     */
    ConstIterator getConstIterator(const Point &aPoint);
 
    /** 
     * Construct a Iterator on the image at a position specified
     * by @c aPoint
     * 
     * @param aPoint a point to construct a Iterator on. 
     * 
     * @return a Iterator on @c aPoint
     */
    Iterator getIterator(const Point &aPoint);
 
    /**
     * @return the domain associated to the image.
     */
    const Domain &domain() const
    {
      return myDomain;
    }

    ///@todo temporary copy of translatedomain in the container
    void translateDomain(const Vector &vec)
    {
      myDomain = Domain(myDomain.lowerBound() + vec, myDomain.upperBound() + vec);
    }

    ///@todo temporary copy of translatedomain in the container
    Vector extent() const
    {
      return   myDomain.upperBound() -  myDomain.lowerBound() 
	+ Vector::diagonal();
    }
    
    /////////////////////////// Custom Iterators ////////////////////:
    /**
     * Specific SpanIterator on ImageContainerBySTLVector.
     *
     * @tparam Domain the HyperRectDomain on which the iterator iterates.
     * @tparam Value
     */
    class SpanIterator
    {

      friend class ImageContainerBySTLVector<Domain, Value>;

    public:

      typedef std::bidirectional_iterator_tag iterator_category; ///\todo construct a RANDOM-ACCESS iterator
      typedef Value value_type;
      typedef ptrdiff_t difference_type;
      typedef Value* pointer;
      typedef Value& reference;

      /**
       * Constructor.
       *
       * @param p starting point of the SpanIterator
       * @param aDim specifies the dimension along which the iterator will iterate
       * @param aMap pointer to the imageContainer
       */
      SpanIterator( const Point & p ,
		    const Dimension aDim ,
		    ImageContainerBySTLVector<Domain, Value> *aMap ) :  myMap ( aMap ), myDimension ( aDim )
      {
	myPos = aMap->linearized(p);

	//We compute the myShift quantity
	myShift = 1;
	for (Dimension k = 0; k < myDimension  ; k++)
	  myShift *= (aMap->myDomain.upperBound()[k] - aMap->myDomain.lowerBound()[k] + 1);
      }


      /**
       * Set a value at a SpanIterator position.
       *
       * @param aVal the value to set.
       */
      inline 
      void setValue(const Value aVal)
      {
	(*myMap)[ myPos ] = aVal;
      }

      /**
       * operator* on SpanIterators.
       *
       * @return the value associated to the current position.
       */
      inline
      const Value & operator*() 
      {
	return (*myMap)[ myPos ];
      }

      /**
       * Operator ==.
       *
       * @return true if this and it are equals.
       */
      inline
      bool operator== ( const SpanIterator &it ) const
      {
	return ( myPos == it.myPos );
      }

      /**
       * Operator !=
       *
       * @return true if this and it are different.
       */
      inline
      bool operator!= ( const SpanIterator &it ) const
      {
	return ( myPos != it.myPos );
      }

      /**
       * Implements the next() method: we move on step forward.
       *
       **/
      inline
      void next()
      {
	myPos += myShift;
      }

      /**
       * Implements the prev() method: we move on step backward.
       *
       **/
      inline
      void prev()
      {
	ASSERT((long int) myPos - myShift > 0);
	myPos -= myShift;
      }

      /**
       * Operator ++ (++it)
       *
       */
      inline
      SpanIterator &operator++()
      {
	this->next();
	return *this;
      }

      /**
       * Operator ++ (it++)
       *
       */
      inline
      SpanIterator &operator++ ( int )
      {
	SpanIterator tmp = *this;
	++*this;
	return tmp;
      }

      /**
       * Operator -- (--it)
       *
       */
      inline
      SpanIterator &operator--()
      {
	this->prev();
	return *this;
      }

      /**
       * Operator -- (it--)
       *
       */
      inline
      SpanIterator &operator-- ( int )
      {
	SpanIterator tmp = *this;
	--*this;
	return tmp;
      }

    private:
      ///Current Point in the domain
      Size myPos;

      /// Copy of the underlying images
      ImageContainerBySTLVector<Domain, Value> *myMap;

      ///Dimension on which the iterator must iterate
      Dimension  myDimension;

      ///Padding variable
      Size myShift;

    };

    /**
     * Set a value on an Image at a position specified by an SpanIterator.
     *
     * @param it  iterator on the location.
     * @param aValue the value.
     */
    void setValue(SpanIterator &it, const Value &aValue)
    {
      it.setValue(aValue);
    }


    /**
     * Create a begin() SpanIterator at a given position in a given
     * direction.
     *
     * @param aPoint the starting point of the SpanIterator.
     * @param aDimension the dimension on which the iterator iterates.
     *
     * @return a SpanIterator
     */
    SpanIterator spanBegin(const Point &aPoint, const Dimension aDimension)
    {
      return SpanIterator ( aPoint, aDimension, this);
    }

    /**
     * Create an end() SpanIterator at a given position in a given
     * direction.
     *
     * @param aPoint a point belonging to the current image dimension (not
     * necessarily the point used in the span_begin() method.
     * @param aDimension the dimension on which the iterator iterates.
     *
     * @return a SpanIterator
     */
    SpanIterator spanEnd(const Point &aPoint, const Dimension aDimension)
    {
      Point tmp = aPoint;
      tmp[ aDimension ] = myDomain.upperBound()[ aDimension ] + 1;
      return SpanIterator( tmp, aDimension, this);
    }

    /**
     * Returns the value of the image at a given SpanIterator position.
     *
     * @param it position given by a SpanIterator.
     * @return an object of type Value.
     */
    Value operator()(SpanIterator &it)
    {
      return (*it);
    };



  private:

    /**
     *  Linearized a point and return the vector position.
     * @param aPoint the point to convert to an index
     * @return the index of @param aPoint in the container
     */
    Size linearized(const Point &aPoint) const;

    ///Image Domain
    Domain myDomain;

    // ------------- realization CDrawableWithBoard2D --------------------
  private:


  public:

    /**
     * Default drawing style object.
     * @return the dyn. alloc. default style for this object.
     */
    //DrawableWithBoard2D* defaultStyle() const;

    /**
     * @return the style name used for drawing this object.
     */
    std::string className() const;

  };

  /**
   * Overloads 'operator<<' for displaying objects of class 'Image'.
   * @param out the output stream where the object is written.
   * @param object the object of class 'Image' to write.
   * @return the output stream after the writing.
   */
  template <typename Domain, typename V>
  inline
  std::ostream&
  operator<< ( std::ostream & out, const ImageContainerBySTLVector<Domain, V> & object )
  {
    object.selfDisplay ( out );
    return out;
  }

} // namespace DGtal


///////////////////////////////////////////////////////////////////////////////
// Includes inline functions
#include "DGtal/images/ImageContainerBySTLVector.ih"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined ImageContainerBySTLVector_h

#undef ImageContainerBySTLVector_RECURSES
#endif // else defined(ImageContainerBySTLVector_RECURSES)
