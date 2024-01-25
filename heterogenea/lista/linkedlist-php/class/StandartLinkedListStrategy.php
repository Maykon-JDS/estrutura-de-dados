<?php 

namespace Lista\class;

use Lista\class\LinkedListStrategy;

class StandartLinkedListStrategy extends LinkedListStrategy{
     
    public function getHead() : Node|null
    {

        return $this->head;
    
    }

    public function getTail() : Node|null
    {

        return $this->tail;
    
    }

    public function getIndex(int $index) : Node|null
    {

        $nodeSearch = $this->head;

        for ($i=0; $i <= $index; $i++) { 

            if($nodeSearch == Null){

                return Null;

            }
            else if($i == $index){

                break;

            }

            $nodeSearch = $nodeSearch->getNext();

        }

        return $nodeSearch;
    
    }

    public function popHead() : void
    {

        if($this->head <> Null)
        {

            $this->head = $this->head->getNext();

        }

    }

    public function popTail() : void
    {



    }

    public function popIndex(int $index) : void
    {



    }

    public function addHead(mixed $value) : void
    {

        $node = new Node($value);


        if(!empty($this->head)){

            $node->setNext($this->head);

        }
        else{

        $this->tail = $node;


        }

        $this->head = $node;

    }

    public function addTail(mixed $value) : void
    {

        $node = new Node($value);

        if(!empty($this->head)){

            $nodeSearch = $this->head;
        
            while($nodeSearch->getNext() <> Null)
            {
    
                $nodeSearch = $nodeSearch->getNext();
    
            }

            $nodeSearch->setNext($node);

        }
        else {

            $this->head = $node;

        }

        $this->tail = $node;

    }

    public function addIndex(int $index, mixed $value) : void
    {

        

    }

    public function contains() : bool
    {

        

    }

    public function size() : int
    {

        $node = $this->head;
        
        $size = 0;

        while($node <> Null)
        {

            $size++;

            $node = $node->getNext();

        }

        return $size;
        
    }

}

?>