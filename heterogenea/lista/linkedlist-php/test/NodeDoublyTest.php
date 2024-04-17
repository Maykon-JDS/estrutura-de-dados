<?php

declare(strict_types=1);

use Lista\class\NodeDoubly;

use PHPUnit\Framework\TestCase;

use PHPUnit\Framework\Attributes\TestDox;

use PHPUnit\Framework\Attributes\CoversClass;


#[CoversClass(NodeDoubly::class)]
#[TestDox("NodeDoubly")]
class NodeDoublyTest extends TestCase {

    public function testGetPrevNull() : void
    {

        $node = new NodeDoubly(10);

        $this->assertNull($node->getNext());

    }

    public function testGetPrevNode() : void
    {

        $node1 = new NodeDoubly(10);

        $node2 = new NodeDoubly(23, null, $node1);

        $this->assertEquals($node1, $node2->getPrev());

    }

    public function testSetPrevNull() : void
    {

        $node1 = new NodeDoubly(10);

        $node2 = new NodeDoubly(23, null, $node1);

        $node2->setPrev(null);

        $this->assertNull($node2->getPrev());

    }

    public function testSetPrevNode() : void
    {

        $node1 = new NodeDoubly(10);

        $node2 = new NodeDoubly(23, $node1);

        $node3 = new NodeDoubly(99);

        $node2->setPrev($node3);

        $this->assertEquals($node3, $node2->getPrev());

    }

}


?>