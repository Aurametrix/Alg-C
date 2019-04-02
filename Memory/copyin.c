
/*
 *  Attempt non-blocking copy-on-write optimizations.
 */
       
 if (src_destroy &&
      (src_object == VM_OBJECT_NULL ||
        (src_object->internal &&
         src_object->copy_strategy == MEMORY_OBJECT_COPY_SYMMETRIC &&
         !map_share)
       )
     )
 {
   /*
    * If we are destroying the source, and the object
    * is internal, we can move the object reference
    * from the source to the copy.  The copy is
    * copy-on-write only if the source is.
    * We make another reference to the object, because
    * destroying the source entry will deallocate it.
    */
   vm_object_reference(src_object);
   
   /*
    * Copy is always unwired.  vm_map_copy_entry
    * set its wired count to zero.
    */

   goto CopySuccessful;
